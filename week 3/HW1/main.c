#include <stdio.h>

double CalculateBMI(int weight, int height){
    double heightSqr = (double) height * (double) height;
    double BMI = 703 * (double) weight / heightSqr;
    return BMI;
}
char* BMI(double bmi){
    if(bmi < 18.5)
        return "underweight";
    if(bmi <24.9)
        return "normal";
    if(bmi <29.9)
        return "overweight";
    return "Obese";
}

int main() {
    double bmi = CalculateBMI(149, 70);
    char* status = BMI(bmi);
    printf("BMI = %f\n",bmi);
    printf("is = %s\n", status);
}