#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"


void toLower (char word[]) //lower dode the charcters of the word
{
int lenW=0;
lenW=strlen(word);
for (int i=0; i<lenW ; i++){
    word[i]= tolower(word[i]);
}
}

int checkIfLegalWord(char w[] ) // if legal return 1 -else return 0
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


struct node* createNode() //create new node (struct node)
{
    struct node* newNode= (struct node*) malloc(sizeof(struct node)*26) ;
    
    newNode->count=0;
   if (newNode!=NULL)
   {
        for(int i=0; i<SIZE_LETTERS; i++)
        {
            newNode-> childrens[i]=NULL;
        }
    }
    return newNode;
}

void insert(struct node **root, char* word) //add word to the tree
{
   struct node* currntNode= *root;
   int lenWord=strlen(word);
   int leterIndex=-1;
   
   int i=0;
    while (i<lenWord) 
    {
       leterIndex=*word-A;
        if (currntNode->childrens[leterIndex] == NULL) //if the currLetter does not exist
        {
            currntNode->childrens[leterIndex] =createNode();
        }
        currntNode=currntNode->childrens[leterIndex]; //go to the next Node
        currntNode->letter=word[i];

        i++; //go to the next Letter
    }
     currntNode->count++;

return;
}

void deleteAllTree(struct node* root) //free tree
{
    if(root == NULL) 
    {
        return;
    }
  
    for (int i=0; i<SIZE_LETTERS; i++)
      { 
         if ((root->childrens[i])!=NULL)
         {
            deleteAllTree(root->childrens[i]);
         }
      }
   free(root);
    return;
}

int haveChildren(struct node* currNode)
{
	for (int i = 0; i < SIZE_LETTERS; i++)
	{
	if (currNode->childrens[i])
			return 1;	// found a child
    }
	return 0;
}


//declining order
void printDeclining( struct node* root, int index, char *word) 
{
    if(haveChildren(root)==0) // no children
    {
       word[index]='\0';
        printf("%s %d\n",word,root->count); // print the word and how many word like this we have
        return;
    }
    if (root->count>0)
    {
        word[index]='\0';
        printf("%s %d\n" , word,root->count);
    }

    int i=0;
    while( i <SIZE_LETTERS)
    {
        if(root->childrens[i]!= NULL)
        {
           word[index]=root->childrens[i]-> letter;
            printDeclining(root->childrens[i],index+1,word);
        }
        i++;
    }
}

//Rising order
void printRising( struct node *root, int index, char *word)
 {
    if(haveChildren(root)==0) // have no children
    {
        word[index]='\0';
        printf("%s %d\n",word,root->count); 
        return;
    }
    if (root->count>0)
    {
        word[index]='\0';
        printf("%s %d\n" , word,root->count);
    }
    
    int i=SIZE_LETTERS-1;
    while( i>=0 )
    {
        if(root->childrens[i]!= NULL)
        {
            word[index]=root->childrens[i]-> letter;
            printRising(root->childrens[i],index+1,word);
        }
        i--;
    }
}


