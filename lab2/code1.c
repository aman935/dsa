/***********************************************
Name: Aman Singh
Roll: B15207
Purpose: IC250 Assignment 02 - Towers of Hanoi  
Date: 25/08/2016
***********************************************/
#include<stdio.h>
#include<glib.h>
#include<math.h>
int legal(GSList**, GSList**);
void pop(GSList *);
void push(GSList *,GSList*);
int main(){
  GSList *S,*A,*D;
  GSList **ps,**pd,**pa;
  ps=&S;
  pd=&D;
  pa=&A;
  char b,c;
  S=NULL;
  int n,steps,i;
  scanf("%d",&n);
    S=g_slist_prepend (S,GINT_TO_POINTER(0));
    A=g_slist_prepend (S,GINT_TO_POINTER(0));
    D=g_slist_prepend (S,GINT_TO_POINTER(0));
  for(i=0;i<n;i++)
    S=g_slist_prepend (S,GINT_TO_POINTER(n-i));
  if(n%2==0){
    b='C'; c='B';       
  }
  else {
    c='C'; b='B';
  }
  
  steps=pow(2,n)-1;
  for(i=1;i<=steps;i++){
    if(i%3==1){
      if(legal(ps,pd))
	printf("%d. Move from A to %c\n",i,c);
      else
	printf("%d. Move from %c to A\n",i,c);
    }
    else if(i%3==2){
      if(legal(ps,pa))
	printf("%d. Move from A to %c\n",i,b);
      else
	printf("%d. Move from %c to A\n",i,b);
    }
    else {
      if(legal(pa,pd))
	printf("%d. Move from %c to %c\n",i,b,c);
      else
	printf("%d. Move from %c to %c\n",i,c,b);
    }
  }
  return 0;
}

int legal(GSList **a,GSList **b){
  if((( GPOINTER_TO_INT((*b)->data) > GPOINTER_TO_INT((*a)->data)&& GPOINTER_TO_INT((*a)->data)!=0)) || GPOINTER_TO_INT((*b)->data)==0){
    /* printf("1. %d\tgoes to %d\n",GPOINTER_TO_INT ((*a)->data),GPOINTER_TO_INT ((*b)->data)); */
    *b=g_slist_prepend(*b,(*a)->data);
    *a=g_slist_remove_link(*a,*a); 
    return 1;
  }
  else{    
    /* printf("2. %d\tgoes to%d\n",GPOINTER_TO_INT ((*b)->data),GPOINTER_TO_INT ((*a)->data)); */
    *a=g_slist_prepend(*a,(*b)->data);
    *b=g_slist_remove_link(*b,*b); 
    return 0;
  }
}

void pop(GSList *a){
 
}
void push(GSList *a,GSList *b){
 
}
