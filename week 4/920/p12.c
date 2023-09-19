#include <stdio.h>

#define SIZE 10

int main() {


    int a = 3;
    int b = 6;

    a = b;


    printf("a = %d\n",a);
    printf("a = %ld\n",&a);


    return 0;
}