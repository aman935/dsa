#include <stdio.h>
#include <stdlib.h>

void  dijkstra(int **Mat, int src,int V,int n);

int main()
{
  int V,E; // V-> Hostels and E-> No. of Paths
  printf("\n INPUT: \n");
  scanf("%d%d",&V,&E);
  getchar();
  int **Mat=(int**)malloc(sizeof(int*)*V);	// 2D Matrix
  int a,b;
  for (int i = 0; i < V; ++i){
    Mat[i]=(int*)malloc(sizeof(int)*V);
    for (int j = 0; j < V; ++j) {	
      if(i==j)	Mat[i][j]=0;
      else	Mat[i][j]=-1;
    }
  }
  for (int i = 0; i < E; ++i){
    scanf("%d %d",&a,&b);
  get:
    scanf("%d",&Mat[a-1][b-1]);
    if(Mat[a-1][b-1]<0) {
      printf("\n Weight should be positive... Please Re-enter Weight only\n");
      goto get;
    }
  }
  int H,NCS; //the no. of hostels conducting CS
  scanf("%d%d",&H,&NCS);
  getchar();
  int cs[10];
  for (int i = 0; i < NCS; ++i)
    scanf("%d",&cs[i]);
  printf("\n OUTPUT: \n");		
  for (int i = 0; i < NCS; ++i) {
    if(cs[i]==H)	printf("%d \t\t\t 0.0\n", H);
    else dijkstra(Mat,H-1,V,cs[i]-1);	
  }
  return 0;
}
  
void  dijkstra(int **Mat, int src,int V,int n){
  int dist[20],flag[20],least,min=100;
  for (int i = 0; i < V; i++) {
    dist[i] = 100;
    flag[i] = 0;
  }
  dist[src] = 0;
  for (int i = 0; i < V-1; i++) {
    for (int j = 0; j < V; ++j) {
      if (flag[j] == 0 && dist[j] <= min) {	
	min = dist[j];
	least = j;
      }
    }
    min=100;
    flag[least] = 1;
    for (int v = 0; v < V; v++) {
      if (!flag[v] && Mat[least][v]>0 && dist[least] != 100 && dist[least]+Mat[least][v] < dist[v])
	dist[v] = dist[least] + Mat[least][v];
    }
  }
  printf("%d \t\t\t %d.0\n", n+1, dist[n]);
}
