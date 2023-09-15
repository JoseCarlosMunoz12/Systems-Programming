#include <stdio.h>

//function prototype
void printGivenTimes(int value);


int main() {
    
    int x;

    printf("Please enter a number between 1 and 5 (inclusively)\n");
    scanf("%d",&x);



    while ((x > 5) || (x < 1)) {
        
        
        printf("Please enter a number between 1 and 5 (inclusively)\n");
        scanf("%d",&x);

    } 
    
    
    printGivenTimes(x);


    return 0;

}

//function definition
void printGivenTimes(int value) {
    for (int i = 0; i< value; i++) {
        printf("One more time?\n");
    }
}