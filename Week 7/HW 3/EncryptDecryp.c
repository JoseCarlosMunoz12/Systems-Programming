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
void RandomReplacementDecryption(char* inputFileName, char* outputFileName, int offset);
/// Find corresponding value in array
char getValue(char* array, char c, int size);

int main(){
	srand(time(NULL));
	int offset = rand() % 25;//randomly selected offset value
	char* inputFile = "";
	char* encryptedFile = "";
	char* decryptedFile = "";
	EncryptDecryptFunc(CeaserEncryption,inputFile, encryptedFile,offset);
	EncryptDecryptFunc(CeaserDecryption,encryptedFile, decryptedFile,offset);
	
	char* encryptedFile1 = "";
	char* decryptedFile1 = "";
	offset = rand() % 25
	EncryptDecryptFunc(RandomReplacementEncrypt,inputFile, encryptedFile1,offset);
	EncryptDecryptFunc(RandomReplacementDecryption,encryptedFile1, decryptedFile1,offset);
	
}

void EncryptDecryptFunc(void(*func)(char* ,char* ,int ), char* inputFileName,char* outputFileName,int offset){
	(*func)(inputFileName, outputFileName, offset);
}

void CeaserEncryption(char* inputFileName, char* outputFileName, int offset){
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	fprintf(oFile, "%d",offset);
	char line[250];
	int offset2 = rand() % 25;
	while(fscanf(iFile, "%s", line) == 1){
		for(int ii = 0; ii < 250; ii++)
		{
			if(line[ii] == '\0')
				break;
			int mod = ii % 2;
			if(mod == 0)
				line[ii]=Encrypt(line[ii],offset);
			else
				line[ii]=Encrypt(line[ii],offset2);
		}
		fprintf(oFile, line);
	}
	fclose(iFile);
	fclose(oFile);
}

void CeaserDecryption(char* inputFileName, char* outputFileName, int offset){
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	char line[250];
	int offset2;
	fscanf(iFile, "%d", &offset2)
	while(fscanf(iFile, "%s", line) == 1){
		for(int ii = 0; ii < 250; ii++)
		{
			if(line[ii] == '\0')
				break;
			int mod = ii % 2;
			if(mod == 0)
				line[ii]=Decrypt(line[ii],offset);
			else
				line[ii]=Decrypt(line[ii],offset2);
		}
		fprintf(oFile, line);
	}
	
	fclose(iFile);
	fclose(oFile);
}

void RandomReplacementEncrypt(char* inputFileName, char* outputFileName, int offset){
    char xyz[27] = "abcdefghijklmnopqrstuvwyz";
    int size =  26 * 4 ;
    for(int ii = 0; ii < size; ii++)
    {
        int id0 = rand() % 26;
        int id1 = rand() % 26;
        char temp = xyz[id1];
        xyz[id1] = xyz[id0];
        xyz[id0] = temp;
    }
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	fprintf(oFile, "%s\n",xyz);
	char line[250];
	
	while(fscanf(iFile, "%s", line) == 1){
		for(int ii = 0; ii < 250; ii++){
			char temp = line[ii];
			if(temp == '\0')
				break;
			if(isupper(temp){
				int id = temp - 'A';
				temp = toupper(xyz[id])
			}
			else{
				int id = temp - 'a';
				temp = xyz[id]
				
			}
			line[ii]=Encrypt(temp,offset);
		}
		fprintf(oFile, line);
	}
	fclose(iFile);
	fclose(oFile);
	
}
void RandomReplacementDecryption(char* inputFileName, char* outputFileName, int offset){
	FILE *iFile;
	FILE *oFile;
	iFile = fopen(inputFileName, "r");
	oFile = fopen(outputFileName, "w");
	char line[250];
    char xyz[27];
	fscanf(iFile, "%s", xyz);
	
	while(fscanf(iFile, "%s", line) == 1){
		for(int ii = 0; ii < 250; ii++){
			char temp = line[ii];
			if(temp == '\0')
				break;
			if(isupper(temp){
				temp = getValue(xyz,temp);
				temp = toupper(temp);
			}
			else{
				temp = getValue(xyz,temp);
			}
			line[ii]= Decrypt(temp,offset);
		}
		fprintf(oFile, line);
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