#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define inf 100000000;

float min(float a, float b){
  return (a <= b) ? a : b;
}

struct edge{
  int j, k;
  float ratio;
  struct edge *next;
}*head, *temp, *last;

int minIndex;

float bFord(int s, int n, int m ){
  int i, j;
  float d[n];
  float minLen = inf;
  for (i = 0; i < n; i++) {
    d[i] = inf;
  }
  d[s - 1] = 0;
  for (i = 0; i < n - 1; i++) {
    temp = head;
    while(temp!= NULL) {
      // printf("%d\t%d\t%.1f\n", temp->j, temp->k, temp->ratio);
      d[temp->k - 1] = min(d[temp->k - 1], d[temp->j - 1] + temp->ratio);
      if(minLen>d[temp->k - 1]){
	minLen = d[temp->k - 1];
	minIndex = temp->k;
      }
      temp = temp->next;
      for (j = 0; j < n; j++) {
	// 	printf("%.1f\t",d[j] );
      }
    }
    
  }
  

  return minLen;
}

int main(){
  int n, m, s, a, b, i;
  scanf("%d%d", &n, &m);
  float weight, c;
  head =last = NULL;
  for (i = 0; i < m; i++) {
    scanf("%d%d%f", &a, &b, &c);
    temp = (struct edge *)malloc(sizeof(struct edge));
    temp->ratio = c;
    temp->j = a;
    temp->k = b; 
    temp->next =NULL;
    if(i != 0){
      last->next = temp;
      last = temp;
    }
    else{
      head = temp;
      last = temp;
    }
  }
  scanf("%d%f", &s, &weight);
  weight *= pow(10, bFord(s, n, m));
  printf("%d\t%f\n",minIndex, weight);
  return 0;
}
