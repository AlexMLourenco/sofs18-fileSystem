/*
 *  \author Artur Pereira - 2007-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 */

#include "mksofs.h"

#include "rawdisk.h"
#include "core.h"

#include <stdarg.h>
#include <stdio.h>
#include <libgen.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

/* print help message */
static void printUsage(char *cmd_name)
{
    printf("Sinopsis: %s [OPTIONS] supp-file\n"
           "  OPTIONS:\n"
           "  -n name     --- set volume name (default: \"sofs18_disk\")\n"
           "  -i num      --- set number of inodes (default: N/8, where N = number of blocks)\n"
           "  -z          --- set zero mode (default: false)\n"
           "  -q          --- set quiet mode (default: false)\n"
           "  -d          --- set debug mode (default: false)\n"
           "  -b          --- set bin configuration to 600-699\n"
           "  -w          --- set bin configuration to 0-0 (default)\n"
           "  -a num-num  --- add given range of functions to bin configuration\n"
           "  -r num-num  --- remove given range of functions from bin configuration\n"
           "  -h          --- print this help\n", cmd_name);
}

/* print an INFO message */
static void infoMsg(const char *fmt, ...)
{
    /* print the message */
    fprintf(stdout, "\e[00;34m");
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    va_end(ap);
    fprintf(stdout, "\e[0m");
    fflush(stdout);
}

/* print a system error message */
static void errnoMsg(int en, const char *msg)
{
    fprintf(stderr, "\e[00;31m%s: error #%d - %s\e[0m\n", msg, en,
        strerror(en));
}

using namespace sofs18;

/* The main function */
int main(int argc, char *argv[])
{
    const char *volname = "sofs18_disk";    /* volume name */
    uint32_t itotal = 0;    /* total number of inodes, if kept, set value automatically */
    bool quiet = false;        /* quiet mode */
    bool debug = false;        /* debug mode */
    bool zero = false;        /* zero mode */

    /* process command line options */

    int opt;
    while ((opt = getopt(argc, argv, "n:i:qzdbwa:r:h")) != -1)
    {
        switch (opt)
        {
            case 'n':    /* volume name */
            {
                volname = optarg;
                break;
            }
            case 'i':    /* total number of inodes */
            {
                uint32_t n = 0;
                sscanf(optarg, "%u%n", &itotal, &n);
                if (n != strlen(optarg))
                {
                    fprintf(stderr, "%s: Wrong number of inodes value.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                break;
            }
            case 'd':    /* debug mode */
            {
                debug = true;
                break;
            }
            case 'q':    /* quiet mode */
            {
                quiet = true;
                break;
            }
            case 'z':    /* zero mode */
            {
                zero = true;    
                break;
            }
            case 'b':   /* set binary mode: all functios binary */
            {
                soBinSetIDs(600, 799);;
                break;
            }
            case 'w':   /* set work mode: nobinary functios */
            {
                soBinSetIDs(0, 0);;
                break;
            }
            case 'a':   /* add IDs to bynary conf */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d-%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to 'a' option.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                soBinAddIDs(lower, upper);
                break;
            }
            case 'r':   /* remove IDs from bynary conf */
            {
                uint32_t lower, upper;
                uint32_t cnt = 0;
                if ( (sscanf(optarg, "%d-%d %n", &lower, &upper, &cnt) != 2) 
                        or (cnt != strlen(optarg)) )
                {
                    fprintf(stderr, "%s: Bad argument to 'a' option.\n", basename(argv[0]));
                    printUsage(basename(argv[0]));
                    return EXIT_FAILURE;
                }
                soBinRemoveIDs(lower, upper);
                break;
            }
            case 'h':    /* help mode */
            {
                printUsage(basename(argv[0]));
                return EXIT_SUCCESS;
            }
            default:
            {
                fprintf(stderr, "%s: Wrong option.\n", basename(argv[0]));
                printUsage(basename(argv[0]));
                return EXIT_FAILURE;
            }
        }
    }

    /* in debug mode can not be quiet */
    if (debug) quiet = false;

    /* check existence of mandatory argument: storage device name */
    if ((argc - optind) != 1)
    {    
        fprintf(stderr, "%s: Wrong number of mandatory arguments.\n", basename(argv[0]));
        printUsage(basename(argv[0]));
        return EXIT_FAILURE;
    }
    const char *devname = argv[optind];

    /* set probbing system on */
    if (debug)
    {
        soProbeOpen(stdout, 0, 1000); 
    }

    try
    {
        /* open the storage device */
        uint32_t ntotal;
        soOpenRawDisk(devname, &ntotal);

        if (!quiet) 
            infoMsg("Installing a SOFS18 file system in %s.\n", argv[optind]);

        /* compute structural division of the disk */
        uint32_t btotal; // total number of data blocks
        uint32_t rdsize; // number of blocks used by cluster reference table
        if (!quiet) infoMsg("  Computing disk structure... \n");
        computeStructure(ntotal, itotal, btotal, rdsize);
        if (!quiet) infoMsg("    (itotal: %u, rdsize: %u).\n", itotal, rdsize);

        /* filling in the superblock fields: */
        if (!quiet) infoMsg("  Filling in the superblock fields... \n");
        fillInSuperBlock(volname, ntotal, itotal, rdsize);

        /* filling in the free inode list table: */
        uint32_t n = 1;
        if (!quiet) infoMsg("  Filling in the free inode list table... \n");
        n += fillInFreeInodeListTable(n, itotal);

        /* filling in the inode table: */
        if (!quiet) infoMsg("  Filling in the inode table... \n");
        n += fillInInodeTable(n, itotal, rdsize);

        /* filling in the free block list table: */
        if (!quiet) infoMsg("  Filling in the free block list table... \n");
        n += fillInFreeBlockListTable(n, btotal, rdsize);

        /* filling in the root directory: */
        if (!quiet) infoMsg("  Filling in the root directory... \n");
        n += fillInRootDir(n, rdsize);

        /* reset free cluster, if required */
        if (zero)
        {
            if (!quiet) infoMsg("  Filling in free data blocks with zeros... \n    ");
            resetBlocks(n, ntotal - n);
        }

        /* set magic number and save superblock */
        if (!quiet) infoMsg("  Setting magic number... \n");
        SOSuperBlock sb;
        soReadRawBlock(0, &sb);
        sb.magic = MAGIC_NUMBER;
        soWriteRawBlock(0, &sb);

        /* reset dates if required */
#ifdef RESET_DATE
        SOInode inode[InodesPerBlock];
        soReadRawBlock(1, inode);
        inode[0].atime = inode[0].ctime = inode[0].mtime = 0;
        soWriteRawBlock(1, inode);
#endif

        /* close device and quit */
        soCloseRawDisk();
        if (!quiet) 
            infoMsg("A %ld-inodes SOFS18 file system was successfully installed in %s.\n", 
                        sb.itotal, argv[optind]);
    }
    catch (SOException & err)
    {
        fprintf(stderr, "|-- %s\n", err.what());
    }
    catch (int err)
    {
        errnoMsg(err, "Fail formating disk");
        return EXIT_FAILURE;
    }
    
    /* that's all */
    return EXIT_SUCCESS;
}    /* end of main */

