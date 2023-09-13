#include <stdio.h>
#include <stdlib.h>

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
	for(;;){
		char value;
		printf("do you want to calculate your BMI? (y/n): ");
		char *line = NULL;
		size_t len = 0;
		__ssize_t lSize = getline(&line, &len, stdin);		
		if(line[0] == 'n')
			break;
		int weight;
		int height;
		printf("Enter your Weight(pounds): ");
		lSize = getline(&line, &len, stdin);
		weight = atoi(line);
		printf("Enter your Height(inches): ");
		lSize = getline(&line, &len, stdin);
		height = atoi(line);
		double bmi = CalculateBMI(weight, height);
		char* status = BMI(bmi);
		printf("Given your weight: %d and your height: %d, your BMI is %.3f which makes you %s\n",
		weight, height,bmi,status);
		free(line);
	}
    return 0;
}
