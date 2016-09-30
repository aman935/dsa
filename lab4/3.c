#include<stdio.h>
#include<stdlib.h>
struct node{
  int a;
  int b;
  int element;
  struct node* next;
}*q,*temp,*r;
int count ();
void append(int num1,int num2,int num3 );
void display ( struct node *head );

int main(){
  int m,n,count,i,j,d,ans;
  printf("Enter the number of rows and coloumn:\n");
  scanf("%d%d",&m,&n);
  int ar[n],cf[n];
  count=0;

  for (i = 0; i < n; i++){ 
    ar[i]=0;
    cf[i]=0;
  }

  for (i = 0; i < m; i++) {
    for (j=0; j < n; j++) {
      scanf("%d",&d);
      if(d!=0){
	count++;
	cf[j]++;  
	append(i,j,d);
      }
      else continue;
    }
  }
  int an[count][2];
  for (i = 1; i < n; i++) 
    cf[i]+=cf[i-1];
  temp=q;
  while(temp->next!=NULL){
    ar[temp->b]++;
    ans=cf[temp->b-1]+ar[temp->b];
    an[ans][0]=temp->a;
    an[ans][1]=temp->element;
    temp=temp->next;
  }
  for (i = 0; i < count; i++) {
    printf("%d\t%d\t%d\n",i,an[i][0],an[i][1]);
  }
  return 0;
}

void display ( struct node *q )
{
	/* traverse the entire linked list */
  while ( temp != NULL )
	{
	  printf ( "%d\t%d\t%d ", temp -> a,temp->b,temp->element ) ;
		temp = temp -> next ;
	}
	printf ( "\n" ) ;
}

/* counts the number of nodes present in the linked list */
void append(int num1,int num2,int num3 )
{
  if ( q == NULL )  /* if the list is empty, create first node */
    {
      temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
      temp->a=num1;
      temp ->b = num2 ;
      temp->element=num3;
      temp -> next = NULL ;
      q = temp ;
    }
  else
    {
      temp = q ;//temp to q
      
      /* go to last node */
      while ( temp -> next != NULL )
	temp = temp -> next ;
      
      /* add node at the end */
      r = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
      r->a=num1;
      r ->b = num2 ;
      r->element=num3;
      r -> next = NULL ;
		temp -> next = r ;//temp is pointing to last node
    }
}
