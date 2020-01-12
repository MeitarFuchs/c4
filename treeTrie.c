#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treeTrie.h"
#define SIZE 26
#define A 97

void toLower (char word[]){
int lenW=0;
lenW=strlen(word);
for (int i=0; i<lenW ; i++){
    word[i]= tolower(word[i]);
}
}
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


 struct node* createNode()
{
    printf("wellcom create node \n ");

    struct node* newNode= (struct node*) malloc(sizeof(struct node)*26) ;
    newNode->isLeaf =0;
    newNode->count=0;
    //newNode->data=*leterP;
   for(int i=0; i<SIZE; i++)
  { 
    newNode-> childrens[i]=NULL;
  }
    //free(newNode);
    printf("bye create node \n ");
    return newNode;


}

void insert(struct node* root, char* wordP)
{
    //struct node count=0;
    printf("welcome insert \n");
    struct node* currnt=root;
   // int lenWord=strlen(wordP);
    printf("welcome insert1 \n");
   // int i=0;
    int leterIndex=0;
    while (*wordP!= '\0')
    {
        printf("THE LETTER IS %p  \n" ,wordP);
        printf("welcome insert2 \n");
       leterIndex=*wordP - A;
       printf("the letter index is %d \n", leterIndex);//wordP[i]-A;
        if (currnt->childrens[leterIndex] == NULL)
        {
            printf("welcome insert2.5 \n");
            currnt->childrens[leterIndex] =createNode();
        }
        printf("welcome insert 3 \n");
        currnt=currnt->childrens[leterIndex];
       // i++;
       wordP++;
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

int haveChildren(struct node* curr)
{
	for (int i = 0; i < SIZE; i++)
		if (curr->childrens[i])
			return 1;	// child found

	return 0;
}

// void printTree(struct node* root,int deep, char words[])
// {    printf("hello print tree \n");

//     if(root==NULL){
//         printf("the root IS null \n");
//         return; // no words
//     }
//     int sizeOfWord = strlen(words);
//     printf("the root is NOT null \n");
//     for (int i=0; i<sizeOfWord; ++i)

//     {
//         if(root->childrens[i] != NULL)
//         {
//              words[deep]= i + A;
//              deep++;
//              printTree((root)->childrens[i],deep,words);
//         }
//     }
//     printf("the word in print tree is %s \n", words);
// }

//declining order
void printDeclining( struct node* root, int index, char* word) {
    printf("hello print \n ");
    if(haveChildren(root)==0) // no children
    {
        word[index]='\0';
        
        printf("%s %d  \n",word,root->count); // print the word and how many word like this we have
        return;
    }
    if (root->count>0){
        word[index]='\0';

        printf("%s %d  \n" , word,root->count);
    }
    for (int i = 0; i <SIZE; i++)
    {
        if(root->childrens[i]!= NULL){
           word[index]=root->childrens[i]-> data;
           index++;
            printDeclining(root->childrens[i],index, word);
        }
    }
}

//RISING ORDER
void printRising( struct node* root, int index, char* word) {
    printf("hello print \n ");
    if(haveChildren(root)==0) // no children
    {
        word[index]='\0';
        
        printf("%s %d  \n",word,root->count); // print the word and how many word like this we have
        return;
    }
    if (root->count>0){
        word[index]='\0';

        printf("%s %d  \n" , word,root->count);
    }
    for (int i = SIZE-1; i <0; i--)
    {
        if(root->childrens[i]!= NULL){
           word[index]=root->childrens[i]-> data;
           index++;
            printRising(root->childrens[i],index, word);
        }
    }
}


