#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"

int main(int argc, char *argv[])
{

char word[60];
struct node* headP = NULL;
struct node root;//null
headP=&root;
printf("pleas enter your word:   ");
if((scanf("%s", word))==1)
{
char *wP=word;
int lenW=0;
lenW=strlen(word);
for (int i=0; i<lenW ; i++){
    word[i]= tolower(word[i]);
}
if(checkIfLearalWord(word)==1)
{
insert(headP ,wP);
}
else
{
    printf("please enter new word:   ");
}
}

printf("bye main");
return 0;
}