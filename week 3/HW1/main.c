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
	while(true){
		char value;
		printf("do you want to calculate your BMI? (Y/N): ");
		scanf("%c", &value);
		if(value == "N")
			break;		
		int weight;
		int height;
		printf("Enter your Weight(pounds): ");
		scanf("%d", &weight);
		printf("Enter your Height(inches): ");
		scanf("%d", &height);
		double bmi = CalculateBMI(weight, height);
		char* status = BMI(bmi);
		printf("Given your weight: %d and your height: %d, your BMI is %.3f which makes you %s\n",
		weight, height,bmi,status);
	}
    return 0;
}
