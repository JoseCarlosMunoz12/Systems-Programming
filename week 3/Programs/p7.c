#include <stdio.h>

int main() {
    
    int x = 5;
    int y = 3;

    double z = (double)x/y;

    int partial = (int)(z*100);

    z = partial/100.0;


    printf("%d/%d = %.2lf\n", x, y, z);
    
    return 0;

}