#include<stdio.h>
#include<stdlib.h>

int main(){
  int m,n,count,i,j,d,ans;
  printf("Enter the number of rows and coloumn:\n");
  scanf("%d%d",&n,&m);
  int ar[m + 1],cf[m + 1], matrix[n + 1][m + 1];
  count=0;

  for (i = 0; i < m + 1; i++){ 
    ar[i]=0;
    cf[i]=0;
  }

  for (i = 1; i < m + 1; i++) {
    for (j=1; j < n + 1; j++) {
      scanf("%d",&d);
      matrix[i][j] = d;
      if(d!=0){
	count++;
	cf[j]++; 
      }
    }
  }
  int list[count + 1][3], transList[count + 1][3];
  for (i = 1; i <= n; i++) {
    for (j=1; j <= m; j++) {
      if(matrix[i][j] != 0){
	list[l][0] = i;
	list[l][1] = j;
	list[l][2] = matrix[i][j];
      } 
    }
  }
  for (i = 1; i <= m; i++) 
    cf[i]+=cf[i-1];
 
  for(i=1;i<=count;i++)
    {
      check[y[i]]++;
      y_transpose[c_freq[y[i]-1] + check[y[i]]] = x[i];
      x_transpose[c_freq[y[i]-1] + check[y[i]]] = y[i];
      value_transpose[c_freq[y[i]-1] + check[y[i]]] = value[i];
    }
  for (i = 1; i <= count; i++) {
    printf("%d\t%d\t%d\n",list[i][0],list[i][1],list[i][2]);
  }
  return 0;
}
