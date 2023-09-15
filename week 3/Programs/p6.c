#include <stdio.h>

int main() {
    
    int x = 5;
    int y = 3;

    double z = (double)x/y;

    int partial = (int)(z*100);

    z = partial/100.0;


    printf("me is %d\n", x);
    printf("me is %d\n", y);
    printf("me is %.2lf\n", z);
    return 0;

}