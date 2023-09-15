#include <stdio.h>

//function prototype
int factorial(int value);


int main() {
    
    int x;

    printf("Please enter a number between 1 and 5 (inclusively)\n");
    scanf("%d",&x);



    while ((x > 5) || (x < 1)) {
        
        
        printf("Please enter a number between 1 and 5 (inclusively)\n");
        scanf("%d",&x);

    } 
    
    
    printf("factorial(%d) = %d\n", x, factorial(x));


    return 0;

}

//function definition
int factorial(int value) {

    //f(1) = 1
    //f(2) = 2*1
    //f(3) = 3*2*1
    //f(4) = 4*3*2*1
    //recursive formula
    //f(x) = x * f(x-1) 

    //base case
    if (value == 1) {
        return 1;
    } else {
    //recursive case
        return value * factorial(value-1);
    }
}