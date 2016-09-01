#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*stack1,*stack2,*temp;

void create();
void push();
int pop();
//void display();
//void enq();
void menu();
void deQ();
void enQ();
int main(){
  int n,d,i,choice;
  create();
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    printf("Enter the element to be added :");
    scanf("%d",&d);
    push(1,d);
  }
  while(1){
  menu();
  scanf("%d",&choice);
  if(choice==1){
    printf("Enter the element to be added :");
    scanf("%d",&d);
    push(1,d);
     while(stack1!=NULL) { 
     push(2,pop(1)); 
   }
  }
  else if(choice==2){
    while(stack1!=NULL) { 
     push(2,pop(1)); 
   }
    printf("The element %d is removed \n",pop(2));
  }
  else return 0;}
  /* while(stack1!=NULL) {  */
  /*    push(2,pop(1));  */
  /*  }  */
  //display();
}
void deQ(){
  if(stack2!=NULL)
     printf("The element %d is dQ'ed \n",pop(2));
  else
    printf("Stack is empty\n");
}
void enQ(int k){
  if(stack1==NULL&&stack2!=NULL){
    dump(2,1);
    push(1,k);
  }
  else if(stack2==NULL)
    push(2,k);
  dump(1,2);
}

void menu(){
  printf("Enter the choice for the Queue\n1. Enqueue (append element)\n2. Dequeue (remove first element)\n3.Exit\n");}

void create(){
  stack1=NULL;
  stack2=NULL;
}

/* void display(){ */
/*   temp=stack2; */
/*   while (temp!=NULL) { */
/*     printf(" %d  <-  ", temp->data); */
/*     temp=temp->next; */
/*   } */
/*   printf("\n"); */
/* } */

int pop(int choice){
  int d;
  temp=(choice==1)?stack1:stack2;
  d=temp->data;
  if(temp==NULL)
    return 0;
  else
    temp=temp->next;
  if(choice==1){
    free(stack1);
    stack1=temp;
    }
  else {
    free(stack2);
    stack2=temp;
  }
  return d;
}

void push(int choice,int d){
  temp=(struct node *) malloc(sizeof(struct node));
  temp->data=d;
  if(choice==1){
    if(stack1==NULL)
      temp->next=NULL;
    else
      temp->next=stack1;
    stack1=temp;
  }
  else{
    if(stack2==NULL)
      temp->next=NULL;
    else
      temp->next=stack2;
    stack2=temp;
  }
}
