#include <stdio.h>

int main() {
    
    int x;

    printf("Please enter a number between 1 and 5 (inclusively)");
    scanf("%d",&x);



    while ((x > 5) || (x < 1)) {
        
        
        printf("Please enter a number between 1 and 5 (inclusively)");
        scanf("%d",&x);

    } 
    
    printf("valid entry");
        
     

    printf("%d\n", x);
    
    return 0;

}