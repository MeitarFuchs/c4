#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"


int main(int argc, char *argv[])
{
    struct node* head = createNode();
    char tempC = getchar();
    int isEndFile=0;
    int isPrintRising=0;
    int len=0;
    char *currWord = (char*)malloc(sizeof(char)*1);
    int sizeOFWord=sizeof(*currWord);
    char *newWord=NULL;

if(argc >= 2 && strcmp(argv[1],"r")==0)
{
     isPrintRising = 1;
}

while (tempC!=EOF || (tempC==EOF && isEndFile!=1)) //the file dose not end or the 
{
    toLower (tempC); //lower down the letters
     if( tempC!=' ' && tempC!= '\t' && tempC!='\0' && tempC!='\n')
     {
        if (sizeOFWord==len)
        {
            newWord=(char*)realloc(currWord, (size+sizeOFWord)*sizeof(char)); 
                len+=sizeOFWord;

            if(newWord==NULL && currWord!=NULL)
            {
                free(currWord);
                printf("fail");
                exit(1);
            }
            currWord=(char*)calloc(len, sizeof(char));
            strcpy(currWord,newWord);
            free(newWord);
        }
        currWord[len]=tempC;
        len++;
     }


    if((tempC==' ' || tempC=='\t' || tempC=='\0' || tempC=='\n') && tempC!=EOF) //and make sure the flie dose not end
    {
        currWord[len]='\0';
        if(currWord[0]!=' ' && len>=1)
        {
            insert(); ///????????????????????????????????
        }
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

// 	struct node* head = createNode();
//     char line [1024];
//     printf("please enter your word: ");
//     if((scanf("%s", line))==1)
//     char *wP=line;
//     char word [256];
// do{
//     toLower(line);
//     if(checkIfLegalWord(line)==0)
//     printf("Your word is not legal , please enter a new word: \n");
//     while(*wP!='\n')
//     {
//     while (*wP!= '\t' || *wP!= '\n' )
//     {
//     word+=word;
//     }
//     char *words=word;
//     insert(head , words);
//     word=NULL;
//     }
    
// }
// while (*line!= '\n');
// printRising(head ,0,wP);
// printDeclining(head ,0,wP);
// deleteAllTree(head);


// int main(int argc, char *argv[])
// {
// char word[60];
// struct node* headP = NULL;
// struct node root;//null
// char curr; 
// headP=&root;
// printf("pleas enter your word:");
// if((scanf("%s", word))==1)
// {
// char *wP=word;
// toLower(word);
// if(checkIfLegalWord(word)==1)
// {  
// insert(headP ,wP);
// printf("finish insert\n");
// printRising(headP,0,word);
// printf("the word is %s:  " , word);
// }
// else
// {
//     printf("please enter new word: ");
// } 
// }

// printf("bye main \n");
// deleteAllTree(headP);

// return 0;
// }