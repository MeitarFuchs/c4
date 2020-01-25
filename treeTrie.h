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

struct node* createNode();
void insert(struct node **root, char* word); //add word to the tree
void deleteAllTree(struct node* root);
int checkIfLegalWord(char w[]);
void printTree(struct node* root,int deep, char words[]);
void toLower (char word[]);
int haveChildren(struct node* curr);
void printDeclining( struct node* root, int index, char* word);
void printRising( struct node* root, int index, char* word);
