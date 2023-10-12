#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


char Decrypt(char c, int offset);
char Encrypt(char c, int offset);

int main()
{
    srand(time(NULL));
    int doLoop = 1;

    do{
        char data[43] = "y";
        printf("Do you want to Decode/Encode File?\n");
        scanf(" %s",&data);
        if (!strcmp(data,"n") || !strcmp(data, "N") ||
         !strcmp(data, "No") || !strcmp(data, "no"))
         {
            doLoop = 0;
        } else {
            char text[22] = "this is a simple test";
            char encrypt[22];
            char decrypt[22];
            int offset1 = 4;
            int offset2 = rand() % 25;
            for(int ii = 0; ii < 22; ii++)            
                {
                    int mod = ii % 2;
                    int offset = 0;
                    printf("%d ", mod);
                    if (mod == 0)
                        encrypt[ii] = Encrypt(text[ii], offset1);
                    else
                        encrypt[ii] = Encrypt(text[ii], offset2);
                }
            for(int ii = 0; ii < 22; ii++)            
                {
                    int mod = ii % 2;
                    int offset = 0;
                    printf("%d ", mod);
                    if (mod == 0)
                        decrypt[ii] = Decrypt(encrypt[ii], offset1);
                    else
                        decrypt[ii] = Decrypt(encrypt[ii], offset2);
                }
        }

    }while (doLoop);

    return 0;
}

char Decrypt(char c, int offset){
    if(!isalnum(c))
        return c;
    if(isupper(c))
    {
        return (c -'A' - offset + 26) % 26 + 'A';
    }
    return (c -'a' - offset + 26) % 26 + 'a';
    
}
char Encrypt(char c, int offset){
    if(!isalnum(c))
        return c;
    if(isupper(c))
    {
        return (c -'A' + offset) % 26 + 'A';
    }
    return (c -'a' + offset) % 26 + 'a';
}