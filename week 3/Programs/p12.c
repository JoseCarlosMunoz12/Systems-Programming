#include <stdio.h>

int main() {
    
    int x;

    printf("Please enter a number between 1 and 5 (inclusively)");
    scanf("%d",&x);

    if (x <= 5) {
        if (x >= 1) {
            printf("valid entry");
        } else {
            printf("invalid entry");    
        }
    } else {
        printf("invalid entry");
    }
        
        
     

    printf("%d\n", x);
    
    return 0;

}