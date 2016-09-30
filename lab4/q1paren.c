#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{
  char data;
  struct node *next;
}*stack,*temp;

int isEmpty();
void create();
void push(char);
void pop();

int main(int argc, char *argv[])
{
  char ch, k;
  int pal,N,bal;
  create();
  printf("Enter the expression to be checked, Enter 0 for exit:\n");
  bal=1;
  while(1){
    bal=1;
    scanf("%c",&ch);
    if(ch=='0'||ch=='\n')
      break; 
    else{
      if(ch =='('){
	push(ch);
      }
      else if(ch==')'){
	if(isEmpty()){
	  bal=0;
	  break;
	}
	else{
	  pop();
	}
      }
      else bal = 0;
    }
  }
  if(isEmpty()&&bal)
    printf("The expression is Balanced\n");
  else
    printf("The expression is not balanced\n");
  return 0;
}

int isEmpty(){
  if(stack==NULL)
    return 1;
  else return 0;
}

void create(){
  stack=NULL;
 
}
void pop(){
  char d;
  temp=stack;
  if(temp!=NULL){
    d = temp->data;
    temp=temp->next;
    free(stack);
    stack=temp;
  }
}

void push(char d){
  temp=(struct node *) malloc(sizeof(struct node));
  temp->data=d;
  if(stack==NULL)
    temp->next=NULL;
  else
    temp->next=stack;
  stack=temp;
}
