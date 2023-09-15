#include <stdio.h>

int main() {
    
    int x;



    do {

        printf("Please enter a number between 1 and 5 (inclusively)");
        scanf("%d",&x);


    } while ((x > 5) || (x < 1));
    
    printf("valid entry");
        
     

    printf("%d\n", x);
    
    return 0;

}