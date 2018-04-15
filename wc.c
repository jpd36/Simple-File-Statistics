#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "wcfunc.h"

int main(int argc,char *argv[]){

        FILE *filep;
        char filename[200];
        char ch;
        int linecount, wordcount, charcount;

        linecount = -1;
        wordcount = -1;
        charcount = 0;

        strcpy(filename,argv[1]);
        filep = fopen(filename,"r");

        if (filep){
            while ((ch=getc(filep)) != EOF) {
                  if (ch == ' ' || ch == '\n')
                        {++wordcount;}
                  if (ch == '\n')
                        {++linecount;}
                  if (ch != ' ' && ch != '\n')
                        {++charcount;}
            }
                if (charcount>0){
                        ++linecount;
                        ++wordcount;
                }
        }
        else{
            printf("Failed to open file\n");
        }

        print(linecount, wordcount, charcount);
        return 0;
}
