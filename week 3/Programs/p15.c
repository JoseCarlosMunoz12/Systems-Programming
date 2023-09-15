#include <stdio.h>

int main() {
    
    int x;

    printf("Please enter a number between 1 and 5 (inclusively)\n");
    scanf("%d",&x);



    while ((x > 5) || (x < 1)) {
        
        
        printf("Please enter a number between 1 and 5 (inclusively)\n");
        scanf("%d",&x);

    } 
    
    printf("valid entry\n");

    for (int i = 0; i < x; i++) {
        printf("One more time?\n");
    }
         
    printf("\n");

    printf("%d\n", x);
    
    return 0;

}