#include <stdio.h>

#define SIZE 10

int main() {


    int a = 3;
    int b = 6;

    int * aPtr = &a;

    //a = b;

    aPtr = &b;


    printf("a = %d\n",a);
    printf("a = %ld\n",&a);
    printf("a = %ld\n",*aPtr);


    return 0;
}