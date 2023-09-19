#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {


    srand(time(NULL));

    int array[SIZE] = {0};

    for (int i=0; i<SIZE; i++) {
        array[i] = rand() % 10;
    } 

    for (int i=0; i<SIZE; i++) { 
        printf("%d\n",array[i]);
    }



    return 0;
}