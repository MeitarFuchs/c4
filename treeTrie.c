#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"
#define SIZE 26
#define A 97

void toLower (char word[])
{
int lenW=0;
lenW=strlen(word);
for (int i=0; i<lenW ; i++){
    word[i]= tolower(word[i]);
}
}

int checkIfLegalWord(char w[] )
{
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

    return 1;
}


 struct node* createNode()
{

    struct node* newNode= (struct node*) malloc(sizeof(struct node)*26) ;
    newNode->isLeaf =0;
    newNode->count=0;
   
   for(int i=0; i<SIZE; i++)
    newNode-> childrens[i]=NULL;

    return newNode;
}

void insert(struct node* root, char* wordP)
{
    struct node* currnt=root;
    while (*wordP!= '\0')
    {
       int leterIndex=*wordP-A;
        if (currnt->childrens[leterIndex] == NULL)
        {
            currnt->childrens[leterIndex] =createNode();
        }
        currnt=currnt->childrens[leterIndex];
        currnt->data=*wordP;
       wordP++;
    }
     currnt->count++;

return;
}
  void deleteAllTree(struct node* root) //free tree
{
    if(root == NULL) {
    return;
    }
    for (int i=0; i<SIZE; i++)
      { 
         if ((root->childrens[i])!=NULL)
         {
            deleteAllTree(root->childrens[i]);
            root->count =0;
         }
      }

   free(root);
    return;
}

int haveChildren(struct node* curr)
{
	for (int i = 0; i < SIZE; i++)
		if (curr->childrens[i])
			return 1;	// found a child

	return 0;
}


//declining order
void printDeclining( struct node* root, int index, char *word) {
    int i=0;
    if(haveChildren(root)==0) // no children
    {
       word[index]='\0';
        printf("%s %d  \n",word ,root->count); // print the word and how many word like this we have
        return;
    }
    if (root->count>0){
        word[index]='\0';

        printf("%s %d  \n" , word,root->count);
    }
    while( i <SIZE)
    {
        if(root->childrens[i]!= NULL){
           word[index]=root->childrens[i]-> data;
            printDeclining(root->childrens[i],index+1, word);
        }
        i++;
    }
}

//RISING ORDER
void printRising( struct node *root, int index, char *word)
 {
    int i=SIZE-1;
    if(haveChildren(root)==0) // without children
    {
        word[index]='\0';
        printf("%s %d  \n",word,root->count); 
        return;
    }
    if (root->count>0)
    {
        word[index]='\0';
        printf("%s %d  \n" , word,root->count);
    }
    while( i>=0 )
    {

        if(root->childrens[i]!= NULL)
        {
            word[index]=root->childrens[i]-> data;
            printRising(root->childrens[i],index+1, word);
        }
        i--;
    }
}


