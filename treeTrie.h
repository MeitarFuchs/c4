#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define A 97
#define SIZE_LETTERS 26

typedef struct node
{
    char letter;
    long unsigned int count;
    struct node* children [SIZE_LETTERS];

}node;

node* createNode(void); // create new node
void insert(node **root, char* w); //add word to the tree
void deleteTree(node* root); //free all tree
int haveChildren(node *currNode); //checking if the node have children
void printDeclining(node *root, int indexL, char *currWord); //print by Declining order
void printRising(node *root, int indexL ,char *currword); //print by Rising order
