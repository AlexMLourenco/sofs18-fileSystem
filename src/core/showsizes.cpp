#include <iostream>

#include "core.h"

using namespace std;
using namespace sofs18;

int main(void)
{
    cout <<
        "BlockSize: " << BlockSize << endl <<
        "sizeof(SOSuperBlock): " << sizeof(SOSuperBlock) << endl <<
        "sizeof(SOInode): " << sizeof(SOInode) << endl <<
        "sizeof(SODirEntry): " << sizeof(SODirEntry) << endl <<
        "InodesPerBlock: " << InodesPerBlock << endl <<
        "DirentriesPerBlock: " << DirentriesPerBlock << endl <<
        "ReferencesPerBlock: " << ReferencesPerBlock << endl;

    return 0;
}
