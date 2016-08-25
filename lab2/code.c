#include<stdio.h>

void DiscMove(int,char,char,char,int *);
int main(){
  int n,i=1;
  char a='A',b='B',c='C';
  scanf("%d",&n);
  DiscMove(n,a,b,c,&i);
  return 0;
}
// The recursive soln
void DiscMove(int n,char A,char B,char C,int* i){
  if(n==1){
    printf("%d. Move disc from : %c to %c\n",*i,A,C);
    *i+=1;
  }
  else if(n>1){
    DiscMove(n-1,A,C,B,i);
    DiscMove(1,A,B,C,i);
    DiscMove(n-1,B,A,C,i);
  }
}

