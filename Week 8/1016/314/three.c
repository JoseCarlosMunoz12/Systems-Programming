#include <stdio.h>
#include <pwd.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //need a char 
    char * path = malloc(255 * sizeof(char));

    getcwd(path, 255);

    printf("Contents of %s\n",path);

    DIR * dir = opendir(path);


    struct dirent * dirEntry = readdir(dir);

    while (dirEntry != NULL) {
        printf("%s\n",dirEntry->d_name);
        dirEntry = readdir(dir);
    }


}