#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {


    srand(time(NULL));

    int array[SIZE] = {0};

    
    for (int times = 20; times > 0; times--) {
        int randomNumber = rand() % 10;
        printf("randomNumber: %d\n", randomNumber);

        array[randomNumber]++;
    }




    printf("frequency\n");


    for (int i=0; i<SIZE; i++) { 
        printf("%d\n",array[i]);
    }



    return 0;
}