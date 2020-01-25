#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "treeTrie.h"

#define A 97
#define SIZE_LETTERS ((int)26)

node* createNode(void) // create new node
{
    node *root= NULL;
    root=(node *)malloc(sizeof(node));
     int i;
    if (root!=NULL)
    {
        root->count = 0;
        for (i = 0; i<SIZE_LETTERS; i++)
        {
            root->children[i]= NULL;
        }
    }

    return root;
}

void insert(node **root, char* w)//add word to the tree
{
    int i;
     int indexL;
    int lenW= strlen(w);
    node *temp = *root;
    for (i = 0; i < lenW; i++)
    {
        indexL=w[i]-A;
        if (!temp->children[indexL])
        {
            temp->children[indexL]= createNode();
        }
        temp=temp->children[indexL];
        temp->letter= w[i];

    }
    
    temp->count++; //for the last
}

int haveChildren(node *currNode) //checking if the node have children
{
   int ans=0;
    for (size_t i=0; i<SIZE_LETTERS; i++)
    {
        if(currNode->children[i])
           {
                ans=1;
           } 
    }
    return ans;
}


void printDeclining(node *root, int indexL, char *currWord) //print by Declining order
{
    if(haveChildren(root)==0) //no childrens
    {
        currWord[indexL]='\0';
        printf("%s\t%ld\n", currWord, root->count);
        return;
    }
    if (root->count>0)
    {
        currWord[indexL]='\0';
        printf("%s\t%ld\n" , currWord, root->count);
    }

    for (size_t i=0; i<SIZE_LETTERS; i++)
    {
        if(root->children[i]){
            currWord[indexL]= root->children[i]->letter;
            printDeclining(root->children[i], indexL+1, currWord);
        }
    }
} 

void printRising(node *root, int indexL ,char *currword)//print by Rising order
{
    int i=SIZE_LETTERS- 1;
    while ( i>=0 ) 
    {
        if (root->children[i])
        {
            currword[indexL]=root->children[i]->letter;
            printRising(root->children[i], indexL + 1, currword);
        }
        i--;
    }

    if (haveChildren(root)==0) // no childrens
    {
        currword[indexL]='\0';
        printf("%s\t%ld\n", currword, root->count);
        return;
    }

    if (root->count>0 )
    {
        currword[indexL]='\0';
        printf("%s\t%ld\n", currword, root->count);
    }
}

void deleteTree(node* root) //free all tree
{
    
    if (!root) return; 

    for (int i=0; i<SIZE_LETTERS; i++)
    {
        deleteTree(root-> children[i]);
    }

    free(root);
}