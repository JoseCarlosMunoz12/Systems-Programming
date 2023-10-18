#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//Basic Encryption Decryption function for features.
char Encrypt(char c, int k){
	if(!isalpha(c))
		return c;
	if(isupper(c))
		return (c + k - 'A') % 26 + 'A';
	return (c + k - 'a') % 26 + 'a';
}
char Decrypt(char c, int k){
	if(!isalpha(c))
		return c;
	if(isupper(c))
		return (c - k - 'A' + 26) % 26 + 'A';
	return (c - k - 'a' + 26) % 26 + 'a';
}

///Base Functionality
void EncryptDecryptFunc(void(*func)(char* ,char* ,int ), char* inputFileName, char* outputFileName, int offset);

////Specialize Encryption Decryption Functionality
void CeaserEncryption(char* inputFileName, char* outputFileName, int offset);
void RandomReplacementEncrypt(char* inputFileName, char* outputFileName, int offset);

void CeaserDecryption(char* inputFileName, char* outputFileName, int offset);
void RandomReplacementDecrypt(char* inputFileName, char* outputFileName, int offset);
/// Find corresponding value in array
char getValue(char* array, char c, int size);

//GetInput variable from the user
void DecryptEncryption(char* inputfile, char* outputfile, int offset);

int main(){
	char *input = malloc(sizeof(char) * 100);
	int doLoop = 1;
	int checkRepeat = 1;
	do
	{
		if(checkRepeat)
		{
			printf("Do you want to encrypt\\decrypt a file? \n");
			scanf(" %s",input);
		}
		//converts input
		int strLength = strlen(input);
		for(int ii = 0; ii < strLength; ii++)
			input[ii] = tolower(input[ii]);
		if(!strcmp(input, "n") || !strcmp(input, "no")){
			doLoop = 0;			
		} else if(!strcmp(input, "y") || !strcmp(input, "yes")){
			//asks for the input file to be encrypted/decrypted
			printf("What is the name of File to encrypt?\\decrypt\n(include .txt)\n");
			scanf(" %s", input);
			//Get outputfile name of the encrypted/decrypted file
			printf("What is the name of the Output file name?\n(include .txt at the end)\n");
			char* outputFile = malloc(sizeof(char) * 80);
			scanf(" %s",outputFile);
			//Gets the offset an converts it into a integer
			char* offsetStr = malloc(sizeof(char) * 80);
			printf("input the offset\n");
			scanf(" %s", offsetStr);
			int offset = atoi(offsetStr);
			DecryptEncryption(input,outputFile, offset);
			//asks user if they want to decrypt/encrypt again
			do
			{
				printf("Would you like to encrypt\\decrypt another\n(yes or no)\n");
				scanf(" %s", input);
				strLength = strlen(input);
				for(int ii = 0; ii < strLength; ii++)
					input[ii] = tolower(input[ii]);
				if(!strcmp(input, "n") || !strcmp(input, "no")){
					checkRepeat = 0;
					doLoop = 0;
				} else if(!strcmp(input, "y") || !strcmp(input, "yes")){
					checkRepeat = 0;
				} else{
				printf("I am sorry, I could not comprehend your response\nPlease try again\n");
					checkRepeat = 1;
				}
				
			} while (checkRepeat);
			
		}
		else{
			printf("I am sorry, I could not comprehend your response\nPlease try again\n");
		}
	} while (doLoop);
	
	
}
void EncryptDecryptFunc(void(*func)(char* ,char* ,int ), char* inputFileName,char* outputFileName,int offset){
	(*func)(inputFileName, outputFileName, offset);
}

void CeaserEncryption(char* inputFileName, char* outputFileName, int offset){
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	int offset2 = rand() % 25;
	printf("%d\n", offset2);
	fprintf(oFile, "%c\n",offset2 + 'a');
	char *line = malloc(sizeof(char) * 100);
	line = fgets(line, 100, iFile);
	while(line != NULL){
		int size = strlen(line);
		for(int ii = 0; ii < size; ii++)
		{
			int mod = ii % 2;
			if(mod == 0)
				line[ii]=Encrypt(line[ii],offset);
			else
				line[ii]=Encrypt(line[ii],offset2);
		}
		fprintf(oFile,"%s" , line);
		line = fgets(line, 100, iFile);
	}
	fclose(iFile);
	fclose(oFile);
}

void CeaserDecryption(char* inputFileName, char* outputFileName, int offset){
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	char *line = malloc(sizeof(char) * 100);
	int offset2;
	line = fgets(line, 100, iFile);
	offset2 = line[0] - 'a';
	line = fgets(line, 100, iFile);
	while(line != NULL){
		int size = strlen(line);
		for(int ii = 0; ii < size; ii++)
		{
			int mod = ii % 2;
			if(mod == 0)
				line[ii]=Decrypt(line[ii],offset);
			else
				line[ii]=Decrypt(line[ii],offset2);
		}
		fprintf(oFile,"%s" , line);
		line = fgets(line, 100, iFile);
	}
	
	fclose(iFile);
	fclose(oFile);
}

void RandomReplacementEncrypt(char* inputFileName, char* outputFileName, int offset){

	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	char xyz[27] = "abcdefghijklmnopqrstuvwxyz";
    int asize =  26 * 4;
    for(int ii = 0; ii < asize; ii++)
    {
        int id0 = rand() % 26;
        int id1 = rand() % 26;
        char temp = xyz[id1];
        xyz[id1] = xyz[id0];
        xyz[id0] = temp;
    }
	char *line = malloc(sizeof(char) * 100);
	line = fgets(line, 100, iFile);
	fprintf(oFile, "%s\n",xyz);	
	while(line != NULL){
		int size = strlen(line);
		for(int ii = 0; ii < size; ii++){
			char temp = line[ii];
			if(isalpha(temp)){
				if(isupper(temp)){
					int id = temp - 'A';
					temp = toupper(xyz[id]);
				}
				else{
					int id = temp - 'a';
					temp = xyz[id];					
				}
			}
			line[ii]=Encrypt(temp,offset);
		}
		fprintf(oFile,"%s" , line);
		line = fgets(line, 100, iFile);
	}
	fclose(iFile);
	fclose(oFile);
	
}
void RandomReplacementDecrypt(char* inputFileName, char* outputFileName, int offset){
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	char *xyz = malloc(sizeof(char) * 27);
	char *line = malloc(sizeof(char) * 100);
	line = fgets(line, 100, iFile);
	strcpy(xyz, line);
	line = fgets(line, 100, iFile);
	while(line != NULL){
		int size = strlen(line);
		for(int ii = 0; ii < size; ii++){
			char temp = line[ii];
			temp = Decrypt(temp,offset);
			if(isalpha(temp))
			{
				if(isupper(temp)){
					temp = tolower(temp);
					temp = getValue(xyz,temp, 26);
					temp = toupper(temp);
				}
				else{
					temp = getValue(xyz,temp, 26);
				}
			}
			line[ii] = temp;
		}
		fprintf(oFile,"%s", line);
		line = fgets(line, 100, iFile);
	}
	fclose(iFile);
	fclose(oFile);
}

char getValue(char* array, char c, int size){
	for(int ii = 0; ii < size; ii++)
		if(array[ii] == c)
			return ii + 'a';
	return c;
}


void DecryptEncryption(char* inputfile, char* outputfile, int offset){
	printf("Do you want to encrypt or decrypt?\n(type encrypt or decrypt)\n");
	char* deOption = malloc(sizeof(char) * 80);
	scanf(" %s", deOption);
	printf("Do you want to use Ceaser or Random Character cipher?\n(type in Ceaser or Random)\n");
	char* cipherType = malloc(sizeof(char) * 80);
	scanf(" %s", cipherType);
	if(strcmp(deOption, "encrypt") == 0){
		if(strcmp(cipherType, "Ceaser") == 0){
			EncryptDecryptFunc(CeaserEncryption,inputfile,outputfile,offset);
		} else if (strcmp(cipherType, "Random") == 0){
			EncryptDecryptFunc(RandomReplacementEncrypt,inputfile,outputfile,offset);
		}
	} else if (strcmp(deOption, "decrypt") == 0){
		if(strcmp(cipherType, "Ceaser") == 0){
			EncryptDecryptFunc(CeaserDecryption,inputfile,outputfile,offset);
		} else if (strcmp(cipherType, "Random") == 0){
			EncryptDecryptFunc(RandomReplacementDecrypt,inputfile,outputfile,offset);
		}

	}
}