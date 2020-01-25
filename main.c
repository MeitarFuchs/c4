#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "treeTrie.h"

#define A 97
#define ADD 32
#define SIZE_LETTERS ((int)26)
#define W_SIZE 15

int main(int argc , char* argv[]) 
{
    node *root=createNode();
    char *word=NULL;
    word=(char*)malloc(sizeof(char)*1);

    int len=0;
    int size=0;
    char tempC;
    char *newWord=NULL;
    
    int typPrint=0; //0-D 1-R

    if (word==NULL)
    {
        printf("FAIL");
        exit(1);
    }
    
    if( argc>=2 && ( strcmp(argv[1],"r")==0 ) )
    {
        typPrint=1;
    }

    while ((tempC= getc(stdin)) !=EOF )
    {
        if ( (tempC>='A' && tempC<='Z' ) && tempC!=' ' && tempC!='\t' &&  tempC!='\0' && tempC!='\n') 
        {
            char newC=tempC+ADD;
            tempC=newC;
        }
        if ( (tempC>='a' && tempC<='z') && tempC!=' ' && tempC!='\t' &&  tempC!='\0' && tempC!='\n')
        {
            if (len == W_SIZE)
            {
                newWord=(char*)realloc(word,(size+W_SIZE)* sizeof(char)); 
                len += W_SIZE;
                if(newWord==NULL && word!=NULL)
                {
                    free(word);
                    printf("FAIL");

                    exit(1);
                }

                word =(char*)calloc(len,sizeof(char));
                strcpy(word,newWord);
                free(newWord);
            }
            word[len]= tempC;
            len++;
        }

        if (tempC=='\t' || tempC=='\0' || tempC==' ' || tempC=='\n' )
        {
            word[ len ]='\0';
            insert(&root,word);

            len=0;
        }
    }

    if (typPrint==1)
    {
        printRising(root,0,word);
    }else{
        printDeclining(root,0,word);
    }

    deleteTree(root);
    free(word);


    return 0;
}