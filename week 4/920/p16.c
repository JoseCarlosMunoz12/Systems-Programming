#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void printArray(int *array, int size);


int main() {


    int *array = malloc(sizeof(int)*SIZE);


    for (int i=0; i< SIZE; i++) {
        *(array + i) = rand() % 2; 
    }

    printArray(array, SIZE);



    return 0;
}

void printArray(int *array, int size) {

    int count = 0;
    while (count < size) {
        printf("%d\n",*(array++));
        count++;
        
    }
 

}