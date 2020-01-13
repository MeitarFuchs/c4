#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"

int main(int argc, char *argv[])
{
	struct node* head = createNode();
    char line [1024];
    printf("please enter your word: ");
    if((scanf("%s", line))==1)
    char *wP=line;
    char word [256];
do{
    toLower(line);
    if(checkIfLegalWord(line)==0)
    printf("Your word is not legal , please enter a new word: \n");
    while(*wP!='\n'){
    while (*wP!= '\t' || *wP!= '\n' )
    {
    word+=word;
    }
    char *words=word;
    insert(head , words);
    word=NULL;
    }
    
}while (*line!= '\n');
printRising(head ,0,wP);
printDeclining(head ,0,wP);
deleteAllTree(head);
return 0;
}

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