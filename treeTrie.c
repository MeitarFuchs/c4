#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"
#define SIZE 26
#define A 97


int checkIfLearalWord(char w[] )
{
    printf("welcom to check leagal word \n");
    int i=0;
    while (w[i]!='\0')
    {
        if (w[i]>=97 && w[i]<=122)
        {i++;}
        else
        {
            return 0;   
        }
    }
        printf("bye to check leagal word \n");

    return 1;
}


 struct node* createNode(char *leterP)
{
        printf("wellcom create node \n ");

  struct node* newNode= (struct node*) malloc(sizeof(struct node)*26) ;
   newNode->isLeaf =0;
    newNode->count=0;
    newNode->data=*leterP;
   for(int i=0; i<SIZE; i++)
  { newNode->childrens[i]=NULL;}
    free(newNode);
           printf("bye create node \n ");
              return newNode;


}

void insert(struct node* headP, char* wordP)
{
    printf("wellcom insert \n");
    struct node* currnt=headP;
    printf("wellcom insert1 \n");

    while (*wordP)
    {
            printf("wellcom insert2 \n");

    if (currnt->childrens[*wordP - A] == NULL)
        currnt->childrens[*wordP - A] =createNode(wordP);
    printf("wellcom insert 3 \n");

    currnt=currnt->childrens[*wordP-A];
    *wordP++; //maybe without *
    }

    currnt->count= currnt->count+1;
        printf("bye insert \n");

}
 void deleteAllTree(struct node* headP)
{

}


