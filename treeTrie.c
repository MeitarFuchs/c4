#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"
#define SIZE 26
#define A 97


int checkIfLegalWord(char w[] )
{
    printf("welcom to check legal word \n");
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

void insert(struct node* root, char* wordP)
{
    printf("wellcom insert \n");
    struct node* currnt=root;
    int lenWord=strlen(wordP);
    printf("wellcom insert1 \n");
    int i=0;
    int leterIndex=0;
    while (i<lenWord)
    {
        printf("wellcom insert2 \n");
        leterIndex=wordP[i]-A;
        if (currnt->childrens[leterIndex] == NULL)
            currnt->childrens[leterIndex] =createNode(wordP);

        printf("wellcom insert 3 \n");
        currnt=currnt->childrens[leterIndex];
        i++;
    }
    currnt->count= currnt->count+1;

        printf("bye insert \n");

}
  void deleteAllTree(struct node* root) //free tree
{
     int flag=0;
    if(root==NULL) return;   // if there is no tree.
    for (int i=0; i<SIZE; i++)
      {  if (root->childrens[i]!=NULL)
            flag=1;
      }
      if (flag==0)// if we just have a root
      return;
    for (int i = 0; i < SIZE; i++) // free all from the end to the top
        deleteAllTree(root->childrens[i]);
    free(root);

}
void printTree(struct node* root,int deep, char words[])
{
    if(root==NULL)return; // no words

    for (int i=0; i<SIZE; ++i)

    {
        if(root->childrens[i] != NULL)
        {
             words[deep]= i+A;
             printTree(root->childrens[i],deep+1,words);
        }
    }
    printf("%s", words);
}



