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
    FILE * stream = fopen(file ,"rb");

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
            char * newBuff = (char *)malloc(sizeof(char)*1000);
			strcpy(newBuff, buffer);
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
    //get working direct (CWD)
    long totalTime = 0;
    for(int ii = 0; ii < 1000; ii++){
        counter = 0;
        char buffer[256];
        char * fn = getcwd(buffer, 256);
        struct timespec res1;
        struct timespec res2;
        int ret = clock_gettime(CLOCK_REALTIME, &res1);
	    //processsing directory
	    processDirectory(fn);
        //awaiting for threads to be completed
        for(int ii = 0; ii < counter; ii++){
            pthread_join(tid[ii], NULL);
        }
        //output the frequency
        for (int i=0; i<26; i++) {
            printf("%c: %d\n", ('a' + i), frequency[i]);
        }
        //End the timer, i.e., record the ending time
        ret = clock_gettime(CLOCK_REALTIME, &res2);
        long dns =(res2.tv_nsec - res1.tv_nsec);
        if (dns < 0) {
            // Normalize the result
            dns += 1000000000L;
        }
        totalTime += dns;
        printf("Execution time nsec=%ld ns\n", dns);       
        //reset the frequency counter
        for(int jj = 0; jj <26; jj++)
            frequency[jj] = 0; 
    }
    long average = totalTime / (double)1000;
    printf("Average Execution time nsec=%ld ns\n",average);    
    FILE * file = fopen("system4.txt","a");
    fprintf(file,"Average Execution time nsec =%ld ns\n",average);
    fclose(file);    

}