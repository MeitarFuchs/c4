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
struct node* createNode(char* leterP);
void insert(struct node* headP, char* wordP);
void deleteAllTree(struct node* headP);
int checkIfLearalWord(char w[]);