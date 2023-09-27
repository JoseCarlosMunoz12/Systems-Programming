#include <stdlib.h>
#include <stdio.h>

int NeedsACurve(int size, int examID, int *arr, int curveValue )
{
    int num = 0;
    for(int ii = 0; ii < size;ii++)
        num += *((arr + ii*4) + examID);
    int average = num / size;
    return average < curveValue;
}

int SetNewCurve(int size, int examID, int *arr, int maxGrade) 
{
    int max = 0;
    for(int ii = 0; ii < size; ii++)
    {
        int value = *((arr + ii*4) + examID);
        if(value > max)
            max = value;
    }
    int addition = maxGrade - max;
    return addition;
}

int RandomGenerator(int lower, int upper)
{
    int num = ( rand() % (upper - lower + 1) + lower);
    return num;
}

void DisplayStudentAverages(int size, int *arr, int setCurve, int maxGrade)
{
    int curves[4] = {0, 0, 0, 0};
    //calculates the curve needed for each exam
    for (int ii = 0; ii < 4; ii++)
    {
        if(NeedsACurve(size,ii,arr,setCurve))
            curves[ii] = SetNewCurve(size, ii, arr, maxGrade);
        else
            curves[ii] = 0;
    }
    // add the curve to the exams
    for(int ii = 0; ii < size; ii++)
    {
        for(int jj = 0; jj < 4; jj++)
        {
            *((arr + ii * 4) + jj) += curves[jj];
        }
    }
    //Display the Exams
    for(int ii = 0; ii < 100; ii++)
    {
        int average = 0;
        for(int jj = 0; jj < 4;jj++)
        {
            average += *((arr + ii * 4) + jj);
        }
        average /= 4;
        printf("Student %d: %d \n", ii,average);
    }
    //Restore Exams to orignal For recalculation
    for(int ii = 0; ii < size; ii++)
    {
        for(int jj = 0; jj < 4; jj++)
        {
            *((arr + ii * 4) + jj) -= curves[jj];
        }
    }
    
}

int main(){
    int students[100][4]; // initialize 100 students and each student has 4 grades
    //Initialize max and min grade range from the user
    int maxGrade;
    printf("What is the Maximum Possible Grade?\n");
    scanf(" %d", &maxGrade);
    int minGrade;
    printf("What is the Minimum Possible Grade?\n");
    scanf(" %d", &minGrade);
    for(int ii = 0; ii < 100; ii++)
    {
        for(int jj = 0; jj < 4; jj++)
        {
            students[ii][jj] = RandomGenerator(minGrade, maxGrade);
        }
    }
    //ask use if the desired curve is good enough
    int isAcceptable = 0;
    char answer;
    do {
        int curveValue;
        printf("What is your desired Curve?: \n");
        scanf(" %d", &curveValue);
        DisplayStudentAverages(100, (int *)students, curveValue, maxGrade);
        printf("Is this an acceptable curve?(y/n): ");
        scanf(" %c", &answer );
    }
    while (answer == 'n');
    return 0;
}
