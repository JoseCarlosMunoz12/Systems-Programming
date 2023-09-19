#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void pleasesort (int *array, int size, void (*sortingfunction)(int *array, int size));

void gnomesortIterative(int *array, int size);
void gnomesortRecursive(int *array, int size);



void gnomesortSubRecursive(int position, int *array, int size);



int main() {


    int *array = malloc(sizeof(int)*SIZE);


    for (int i=0; i< SIZE; i++) {
        *(array + i) = rand() % 100; 
    }

    pleasesort(array, SIZE, gnomesortIterative);

    for (int i=0; i<SIZE; i++) { 
        printf("%d\n",*(array + i));
    }



    return 0;
}


void pleasesort (int *array, int size, void (*sortingfunction)(int *array, int size)) {
    //call the function
    (*sortingfunction)(array, size);


}

//iterative version
void gnomesortIterative(int *array, int size) {

    int position = 0;
    //more pots to sort
    while (position < size) {
        if (position == 0) {
            //we're at the first pot
            position++;
        } else if (array[position-1] <= array[position]) {
            //they're in order
            position++;
        } else {
            //not in order, so swap
            int temp = array[position - 1];
            array[position-1] = array[position];
            array[position] = temp;
            //go back
            position--;
        }
    }

}





void gnomesortRecursive(int *array, int size) {

    int position = 0;

    gnomesortSubRecursive(position, array, size);

}
void gnomesortSubRecursive(int position, int *array, int size) {
    //printf("%d\n", position);
    if (position < size) {
        if ((position == 0) || (array[position-1] <= array[position])) {
            gnomesortSubRecursive(position+1, array, size);
        } else {
            int temp = array[position - 1];
            array[position-1] = array[position];
            array[position] = temp;
            gnomesortSubRecursive(position-1, array, size);
        }
    }
    
}