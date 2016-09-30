#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{
  char data;
  struct node *next;
}*head,*temp,*hold,*temp1;

void create();
void add();
void menu();
void display();
void reverse();

int main(int argc, char *argv[])
{
  char str[50];
  int choice,pal,i,N,n;
  create();
  while(1){
    menu();
    scanf("%d",&choice);
  if(choice==1){
    printf("Enter the element to be added:\n");
    scanf("%d",&n);
    add(n);
    display();
  }
  else if(choice==2){
    reverse();
    display();
  }
  else return 0;
  }
}

void reverse(){
  temp=NULL;
  temp1 = head;
  while (temp1!=NULL)
    {
      hold=temp1->next;  
      temp1->next=temp;   
      temp=temp1;
      temp1=hold;
    }
    head = temp;
}

void menu(){
  printf("Enter your choice\n1.Add an element to list\n2.Reverse the List\n");
}

void create(){
  head=NULL; 
}

void display(){
  temp=head;
  printf("\nThe List is: \n");
  while (temp!=NULL) {
    printf(" %d  <-  ", temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void add(int d){
  temp=(struct node *) malloc(sizeof(struct node));
  temp->data=d;
     if(head==NULL)
       head=temp;
     else{
       temp1=head;
       while(temp1->next!=NULL)
	 temp1=temp1->next;
       temp1->next=temp;
     }
 }
