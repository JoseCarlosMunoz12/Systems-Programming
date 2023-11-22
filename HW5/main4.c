#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <ctype.h>
#include <dirent.h>
#include <time.h>
#include <pthread.h>

//need a frequency
int frequency[26] = {0};
//threads and thread counter
int counter = 0;
pthread_t tid[10000];
pthread_mutex_t lock; 


void * processFile(void * fn) {
    //whole process file
    printf("Processing File: %s\n",fn);
	char * file = (char *) fn;
    //open the file
    FILE * stream = fopen(file ,"r");

    char c = 0;
    //read the file char by char
    //will stop when C == EOF
    while ((c = fgetc(stream)) != EOF) {
        if (isalpha(c)) {
            //it's an alpha character (a-z)
            c = tolower(c);
            //make darn sure it's a-z
            if (c >= 'a' && c <= 'z') {
                //increment frequency
                frequency[c - 'a']++;
            }
        }
    }

    //close the file
    fclose(stream);

	return NULL;
}

void processDirectory(char * fn) {
    //identify directory
    printf("Working with directory: %s\n",fn);
    //open directory
    DIR * dir = opendir(fn);
    //need a directory entry pointer
    struct dirent * dentry;
    //actually read an entry
    dentry = readdir(dir);
    //loop until dentry is null (no more directory entries)
    while (dentry != NULL) {
        char buffer[1000] = {0};
        strcat(buffer, fn);
        strcat(buffer, "/");
        strcat(buffer,dentry->d_name);
        if (dentry->d_type == DT_DIR) {
            if ((strcmp(dentry->d_name,".") != 0) && (strcmp(dentry->d_name,"..") != 0)) {
                processDirectory(buffer);
            }
            
        } else if (dentry->d_type == DT_REG) {
			char newBuff[1000] = {0};
			strcat(newBuff, buffer);
			pthread_mutex_lock(&lock);
			pthread_create(&tid[counter++], NULL, processFile,(void *)newBuff);
			pthread_mutex_unlock(&lock);
        }
        
        //actually read an entry
        dentry = readdir(dir);
    }
    //close directory
    closedir(dir);


}

int main() {
	pthread_t tid[26];
    //get working direct (CWD)
    char * fn = getcwd(buffer, 256);
    clock_t start = clock();
	//processsing directory
	processDirectory(fn);
    //awaiting for threads to be completed
    for(int ii = 0; ii < counter; ii++){
        printf("waiting on %ul \n", tid[ii]);
        pthread_join(tid[ii], NULL);
    }
    //End the timer, i.e., record the ending time
    clock_t end = clock();
    double diff_t = difftime(end, start);
    //output the frequency
    for (int i=0; i<26; i++) {
        printf("%c: %d\n", ('a' + i), frequency[i]);
    }
   printf("Execution time: %.3f ns\n", diff_t);

}