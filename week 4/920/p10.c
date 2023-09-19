#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7

int main() {


    srand(time(NULL));

    int array[SIZE] = {0};

    
    for (int times = 20000000; times > 0; times--) {
        int randomNumber = 1 + rand() % 6;
        //printf("randomNumber: %d\n", randomNumber);

        array[randomNumber]++;
    }




    printf("frequency\n");


    for (int i=1; i<SIZE; i++) { 
        printf("%d: ", i);
        double freq = array[i]/20000000.0;
        printf("%.5lf", freq);


        
        printf("\n");
        
    }



    return 0;
}