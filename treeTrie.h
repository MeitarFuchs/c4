#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define A 97
#define SIZE_LETTERS 26

struct node
{
char letter;
int count; //long unsigned
struct node* childrens[SIZE_LETTERS];

};
void toLower (char word[]);
struct node* createNode(); //create new node (struct node)
void insert(struct node **root, char* word); //add word to the tree
void deleteAllTree(struct node* root); //free tree
// int checkIfLegalWord(char w[]);
int haveChildren(struct node* currNode);
void printDeclining( struct node* root, int index, char *word);
void printRising( struct node *root, int index, char *word);