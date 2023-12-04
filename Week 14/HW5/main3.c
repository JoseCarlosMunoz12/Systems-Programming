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

void processFile(char * fn, int id) {
    //whole process file
    printf("Processing File: %s\n",fn);
    //open the file
    FILE * stream = fopen(fn ,"r");

    char c = 0;
	char searchChar = 'a' + id;
    //read the file char by char
    //will stop when C == EOF
    while ((c = fgetc(stream)) != EOF) {
        if (isalpha(c)) {
            //it's an alpha character (a-z)
            c = tolower(c);
            //make darn sure it's a-z
            if (searchChar == c) {
                //increment frequency
                frequency[id]++;
            }
        }
    }

    //close the file
    fclose(stream);


}

void processDirectory(char * fn, int id) {
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
        //printf("%s\n",buffer);
        if (dentry->d_type == DT_DIR) {
            if ((strcmp(dentry->d_name,".") != 0) && (strcmp(dentry->d_name,"..") != 0)) {
                processDirectory(buffer, id);
            }
            
        } else if (dentry->d_type == DT_REG) {
            processFile(buffer, id);
        }
        
        //actually read an entry
        dentry = readdir(dir);
    }
    //close directory
    closedir(dir);
}

void * searchCharacter(void *fn){
    //need a buffer to read
    char buffer[256];
    //get working direct (CWD)
    char * dir = getcwd(buffer, 256);
	//cast void pointer to integer ID
	int freq = (int) fn;
	//process directory as normal
	processDirectory(dir, freq);
	return NULL;
}

int main() {
    long totalTime = 0;
    for(int ii = 0; ii < 1000; ii++){
	    pthread_t tid[26];
        struct timespec res1;
        struct timespec res2;
        int ret = clock_gettime(CLOCK_REALTIME, &res1);
        //call method
	    for(int ii = 0; ii < 26; ii++){
	    	int id = ii;
	    	pthread_create(&tid[ii], NULL, searchCharacter,(void *)id);
	    }	
        //awaiting for threads to be completed
        for(int ii = 0; ii < 26; ii++){
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

    FILE * file = fopen("system3.txt","a");
    fprintf(file,"Average Execution time nsec =%ld ns\n",average);
    fclose(file);  
}