#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
}*first,*temp,*last,*stack1,*stack2,*temp;
void createQ();
//void deq(struct node **);
void enq();
int main(){
  int n,i,j;
  printf("Enter the value of n and i:\t");
  scanf("%d%d",&n,&i);
  j=0;
  createQ;
  while (j++<n) {
    if(first==NULL){
      first=(struct node *) malloc(sizeof(struct node));
      first->data=1;
      first->next=NULL;
      temp=first;
    }
    else {
      last=(struct node *) malloc(sizeof(struct node));
      temp->next=last;
      temp=temp->next;
      last->data=j;
      last->next=NULL;
    }
  }
  j=0;
  while(1){
    j++;
    if(first->next==NULL){
      printf("Finally, the person at position %d survives\n",first->data);
      exit(0);
    }
    else{
      if (j%2==0) {
	printf("The person at position %d is removed\n",first->data );
	temp=first;
	first=first->next;
      }
      else {
	enq();
      }
    }
  }
  free(first);
  free(last);
  free(temp);
  return 0;
}
void createQ(){
  last=NULL;
  first=last;
}
void enq(){
  last->next=first;
  last=last->next;
  first=first->next;
  last->next=NULL;
}

void deq(){
free(temp);
}
