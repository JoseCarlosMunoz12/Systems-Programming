#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    

    char * filename = "/home/student/code/me.txt";
    struct stat mystat;

    stat(filename,&mystat);

    printf("Device ID: %d\n",mystat.st_dev);
    printf("Inode: %d\n",mystat.st_ino);

    printf("Size of File (bytes):%d\n",mystat.st_size);
    printf(" #of blocks:%d\n",mystat.st_blocks);
    printf("BlockSize:%d\n",mystat.st_blksize);
    printf("Size of file (via blocks):%d\n",mystat.st_blksize*mystat.st_blocks);

    printf("Last Access: %d\n",mystat.st_atim);
    printf("Last Access (So Ignatius can read it) %s\n",ctime(&mystat.st_atim.tv_sec));


    printf("Last Mod: %d\n",mystat.st_mtim);
    printf("Last Mod (So Ignatius can read it) %s\n",ctime(&mystat.st_mtim.tv_sec));


    printf("Last Status Change: %d\n",mystat.st_ctim);
    printf("Last Status Change (So Ignatius can read it) %s\n",ctime(&mystat.st_ctim.tv_sec));
}