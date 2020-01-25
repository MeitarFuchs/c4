#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"


int main(int argc, char *argv[])
{
    struct node* head= createNode();
    char *currWord=NULL;
    currWord = (char*)malloc(sizeof(char)*1);
    if (currWord == NULL)
    {
        printf("fail");
        exit(1);
    }
    int sizeOFWord=sizeof(*currWord);
    char *newWord=NULL;
    
    char tempC = getchar();

    int len=0;

    int isEndFile=0;
    int isPrintRising=0;
    

if(argc >= 2 && strcmp(argv[1],"r")==0)
{
     isPrintRising= 1;
}

while (tempC!=EOF || (tempC==EOF && isEndFile!=1)) //the file dose not end or the 
{
    toLower (tempC); //lower down the letters
     if(tempC!=' ' && tempC!= '\t' && tempC!='\0' && tempC!='\n' && tempC>=A && tempC<='z')
     {
        if (sizeOFWord==len)
        {
            newWord=(char*)realloc(currWord, (sizeOFWord)*sizeof(char)); 
            len+=sizeOFWord;

            if( currWord!=NULL && newWord==NULL)
            {
                free(currWord);
                printf("fail");
                exit(1);
            }
            currWord=(char*)calloc(len,sizeof(char));
            strcpy(currWord,newWord);
            free(newWord);
        }
        currWord[len]=tempC;
        len++;
     }


    if((tempC==' ' || tempC=='\t' || tempC=='\0' || tempC=='\n') && tempC!=EOF) //and make sure the flie dose not end
    {
        currWord[len]='\0';
        insert(&head,currWord); 
       
        len=0;
    }

    if(tempC==EOF)
         isEndFile=1; // 1=true- the file end

    tempC=getchar();
}


if (isPrintRising==1) // was a input
    {
        printRising (head,0, currWord);
    }
else
    {
        printDeclining(head,0, currWord);
    }

deleteAllTree(head);
free(currWord);
return 0;
}
