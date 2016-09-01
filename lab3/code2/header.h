#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*stack1,*stack2,*temp;

void create();
void push();
int pop();
void displayQ(); 
void menu();
void deQ();
void enQ();
void dump(int,int);
