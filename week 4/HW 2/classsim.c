#include <stdlib.h>
#include <stdio.h>

int NeedsACurve(int size, int examID, int *arr, int curveValue )
{
    int num = 0;
    for(int ii = 0; ii < size;ii++)
        num += *((arr + ii*4) + examID);
    int average = num / size;
    printf("%d\n", average);
    return average < curveValue;
}
void SetNewCurve(int size, int examID, int *arr)
{
    int max = 0;
    for(int ii = 0; ii < size; ii++)
    {
        int value = *((arr + ii*4) + examID);
        if(value > max)
            max = value;
    }
    int addition = 100 - max;
    printf("addition is %d \n", addition);
    for(int ii = 0; ii < size; ii++)
        *((arr + ii*4) + examID) += addition;
}
int RandomGenerator(int lower, int upper)
{
    int num = ( rand() % (upper - lower + 1) + lower);
    return num;
}

int main(){
    int students[100][4]; // initialize 100 students and each student has 4 grades
    //Initialize random grades
    for(int ii = 0; ii < 100; ii++)
    {
        for(int jj = 0; jj < 4; jj++)
        {
            students[ii][jj] = RandomGenerator(60, 100);
        }
    }
    
    for(int ii =0; ii < 4; ii++)
    {
        int needsCurve = NeedsACurve(100,ii,(int *)students,75);
        if(needsCurve)
            SetNewCurve(100,ii,(int *)students);
    }
    for(int ii = 0; ii < 100; ii++)
    {
        int average = 0;
        for(int jj = 0; jj < 4;jj++)
        {
            printf("%d ", students[ii][jj]);
            average += students[ii][jj];
        }
        printf("\n");
        average /= 4;
        printf("Student %d: %d \n", ii,average);
    }
    return 0;
}
