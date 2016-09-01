#include "header.h"
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
  dump(1,2);
  displayQ();
  while(1){
  menu();
  scanf("%d",&choice);
  if(choice==1){
    printf("Enter the element to be added :");
    scanf("%d",&d);
    enQ(d);
    
  }
  else if(choice==2)
    deQ();
  else return 0;}
}
