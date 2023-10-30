#include <stdio.h>
#include <pwd.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //need a char 
    char * path = malloc(255 * sizeof(char));

    getcwd(path, 255);

    printf("%s\n",path);

}