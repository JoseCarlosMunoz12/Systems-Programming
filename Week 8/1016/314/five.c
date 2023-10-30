#include <stdio.h>
#include <pwd.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

void printDirectoryContents(char * path);

int main() {
    //need a char 
    char * path = malloc(255 * sizeof(char));

    getcwd(path, 255);

    printf("Contents of %s\n",path);

    printDirectoryContents(path);

}

void printDirectoryContents(char * path) {


    DIR * dir = opendir(path);


    struct dirent * dirEntry = readdir(dir);

    while (dirEntry != NULL) {
        
        if (dirEntry->d_type == DT_DIR) {
            printf("Directory: %s\n",dirEntry->d_name);
        } else if (dirEntry->d_type == DT_REG) {
            printf("File: %s\n",dirEntry->d_name);
        }
        dirEntry = readdir(dir);
    }


}