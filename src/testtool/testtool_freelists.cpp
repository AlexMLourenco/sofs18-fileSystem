#include "testtool.h"

#include "freelists.h"

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace sofs18;

/* ******************************************** */

static FILE * fin = stdin;

/* ******************************************** */
/* alloc inode */
static uint32_t iType[] = { S_IFREG, S_IFDIR, S_IFLNK };

static const char * msgType[] = { "file", "dir", "symlink" };

void allocInode(void)
{
    /* ask for type */
    promptMsg("Inode type (1 - file, 2 - dir, 3 - symlink): ");
    int t;
    fscanf(fin, "%d", &t);
    fPurge(fin);
    if (t < 1 || t > 3)
    {
        errorMsg("Wrong type: %d", t);
        return;
    }
    uint32_t type = iType[t-1];

    /* call function */
    uint32_t in = soAllocInode(type);

    /* print result */
    resultMsg("Inode number %u allocated (%s)\n", in, msgType[t-1]);
}

/* ******************************************** */
/* free inode */
void freeInode(void)
{
    /* ask for inode number */
    promptMsg("Inode number: ");
    uint32_t in;
    fscanf(fin, "%u", &in);
    fPurge(fin);

    /* call function */
    soFreeInode(in);
    /* print result */
    resultMsg("Inode number %u freed\n", in);
}

/* ******************************************** */
/* replenish inode retrieve cache */
void replenishIRCache(void)
{
    /* call function */
    soReplenishIRCache();

    /* print result */
    resultMsg("replenish of IRCache done\n");
}

/* ******************************************** */
/* deplete inode insertion cache */
void depleteIICache(void)
{
    /* call function */
    soDepleteIICache();

    /* print result */
    resultMsg("deplete of IICache done\n");
}

/* ******************************************** */
/* alloc data block */
void allocDataBlock(void)
{
    /* call function */
    uint32_t cn = soAllocDataBlock();

    /* print result */
    resultMsg("Data block number %u allocated\n", cn);
}

/* ******************************************** */
/* free file block */
void freeDataBlock(void)
{
    /* ask for block number */
    promptMsg("Data block number: ");
    uint32_t cn;
    fscanf(fin, "%u", &cn);
    fPurge(fin);

    /* call function */
    soFreeDataBlock(cn);

    /* print result */
    resultMsg("Data block number %u freed\n", cn);
}

/* ******************************************** */
/* deplete block insertion cache */
void depleteBICache(void)
{
    /* call function */
    soDepleteBICache();

    /* print result */
    resultMsg("deplete of IICache done\n");
}

/* ******************************************** */
/* replenish block retrieve cache */
void replenishBRCache(void)
{
    /* call function */
    soReplenishBRCache();

    /* print result */
    resultMsg("replenish of IRCache done\n");
}

/* ******************************************** */
