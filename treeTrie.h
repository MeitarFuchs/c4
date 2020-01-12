#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26
#define A 97


struct node
{
char data;
int count;
struct node* childrens[SIZE];
int isLeaf;// 1-if it is a leaf, 0- if it not

};
struct node* createNode();
void insert(struct node* headP, char* wordP);
void deleteAllTree(struct node* root);
int checkIfLegalWord(char w[]);
void printTree(struct node* root,int deep, char words[]);
void toLower (char word[]);
int haveChildren(struct node* curr);
void printDeclining( struct node* root, int index, char* word);
void printRising( struct node* root, int index, char* word);
