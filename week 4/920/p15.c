#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {


    int *array = malloc(sizeof(int)*SIZE);


    for (int i=0; i< SIZE; i++) {
        *(array + i) = rand() % 2; 
    }

    for (int i=0; i<SIZE; i++) { 
        printf("%d\n",*(array + i));
    }



    return 0;
}