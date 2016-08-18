/***********************************************
Name: Aman Singh
Roll: B15207
Purpose: IC250 Assignment 01 - Question 1 - FILE I/O 
Date: 17/08/2016
***********************************************/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int **matrix(int ,int );
void which_file(int *,int *,char *);
int *new_element(int, int*);

int main(int argc,char *argv[]){
  unsigned long long int countA=0,countB=0;
  long long int hist[256]={0},c_hist[256]={0},sum=0,total=0,k=0;
  int **mtrx,element,i=0,j=0,opt_th,c=0,row=0,col=0;
  double meanDiff,meanA,meanB,sdA,sdB,nP,d_dash,cpu_time_used,nPmin;
  FILE *fp,*fp1;
  fp=fopen(argv[1],"r");
  fp1=fopen("res.txt","w");
  which_file( &row, &col, argv[1] );
  mtrx=matrix(row,col);
  clock_t start,end;
  start=clock();
  while(fscanf(fp,"%d",&element)==1 && i<row )
    {
      if(j==col){
	j=0; i++;
      }
      mtrx[i][j]=element;
      hist[ element ]++;
      sum+=element;
      j++;
  }
  end=clock();
 fprintf(fp1,"Time taken in part A: %lf\n",(double)(end-start)/CLOCKS_PER_SEC); 
  printf("Enter the choice for method \n 1. Iterative \n2.Histogram\n");
  nPmin=10;
  scanf("%d",&c);
  clock_t end1,start1;
  if(c==1){
    start1=clock();
    FILE *out;
    out=fopen("result.dat","w");
    fprintf(out,"Th\t d'\t nP\n");
    for( i=0; i<=255; i++ ){
      meanA=0; meanB=0; countA=0; countB=0,sdA=0,sdB=0;
      for(j=0; j<row; j++){
	for(  k=0; k<col; k++ ){
	  if(mtrx[j][k]<=i){
	    meanA+=mtrx[j][k];
	    countA++;
	  }
	  else{
	    meanB+=mtrx[j][k];
	    countB++;
	  }
	}
      }
      if(!countA)
	countA=1;
      if(!countB)
	countB=1;
      meanA/=countA;
      meanB/=countB;
      for(j=0; j<row; j++){
	for( k=0; k<col; k++ ){
	  if(mtrx[j][k]<=i){
	    sdA+=pow((mtrx[j][k]-meanA),2)/countA;
	  }
	  else{
	    sdB+=pow((mtrx[j][k]-meanB),2)/countB;
	  }
	} 
      }
      sdA=sqrt(sdA);
      sdB=sqrt(sdB);
      meanDiff=fabs(meanA-meanB);
      d_dash=meanDiff/sqrt(sdA*sdA+sdB*sdB);
      nP=(double)countA/countB;
      if(fabs(1-nP)<nPmin){
	nPmin=fabs(1-nP);
	opt_th=i;
      }
      fprintf(out,"%d\t %lf\t %lf\n",i,d_dash,nP);
    }
    end1=clock();
    fprintf(fp1,"\nOptimum Threshold is of :%d\n",opt_th);
    fprintf(fp1,"\nTime taken for part B:%lf\n", (double)(end1-start1)/CLOCKS_PER_SEC );
    char *commands2[] = {"set title \"Threshold vs Discriminative Index\"", "set xrange[0:254]", "set yrange[0:6]", "plot 'result.dat' using 1:2 with lines"};
	char *commands1[] = {"set title \"Threshold vs N_Ratio\"", "set xrange[0:254]", "set yrange[0:18000]", "plot 'result.dat' using 1:3 with lines", };
	char *commands3[] = {"set title \"Discriminative Index vs N_Ratio\"", "set xrange[0:6]", "set yrange[0:18000]", "plot 'result.dat' using 2:3 with lines"};
	FILE *plot1,*plot2,*plot3;
	plot1 = popen("gnuplot -persistent", "w");
	plot2 = popen("gnuplot -persistent", "w");
	plot3 = popen("gnuplot -persistent", "w");
	for(i=0;i<4;i++)
	  {
	    fprintf(plot1, "%s\n", commands1[i]);
	    fprintf(plot2, "%s\n", commands2[i]);
	    fprintf(plot3, "%s\n", commands3[i]);
	  }
  }
    //To calculate the Threshold by Histogram and Cumulative Histogram
  else{
    clock_t end2,start2;
    nPmin=100;
    start2=clock();
    FILE *out1;
    out1=fopen("result1.dat","w");
    c_hist[0]=hist[0];
    for(j=1;j<256;j++){
      c_hist[j]=c_hist[j-1]+hist[j];
    }
    
    for(i=0;i<256;i++){
      for(j=0;j<=i;j++){
	meanA+=hist[j]*j;
      }
      meanB=sum-meanA;
      if(c_hist[i]==0 || c_hist[i]==total){
	c_hist[i]=-1;
	meanA=0;
      }
      meanA/=c_hist[i];
      total=row*col;
      meanB/=(total-c_hist[i]);
      
      for(j=0;j<=i;j++){
	sdA+=(j-meanA)*(j-meanA)*hist[j];
      }
      sdA/=c_hist[i];
      sdA=sqrt(sdA);
      for(j=i+1;j<=255;j++){
	sdB+=(j-meanB)*(j-meanB)*hist[j];
      }
      sdB/=(total-c_hist[i]);
      sdB=sqrt(sdB);
      meanDiff=abs(meanA-meanB);
      d_dash=meanDiff/sqrt(sdA*sdA+sdB*sdB);
      nP=(double)c_hist[i]/(total-c_hist[i]);
      if( (double) fabs(1.0-nP) < nPmin ){
	nPmin=(double)fabs(1.0-nP);
	opt_th=i;
      }
      fprintf(out1,"%d\t %lf\t %lf\n",i,d_dash,nP);
    }
    end2=clock();
    fprintf(fp1,"\nTime taken for part C:%lf\n", (double)(end2-start2)/CLOCKS_PER_SEC );
    fprintf(fp1,"\nOptimum Threshold is of :%d\n",opt_th);
    char *commands2[] = {"set title \"Threshold vs Discriminative Index\"", "set xrange[0:254]", "set yrange[0:6]", "plot 'result1.dat' using 1:2 with lines"};
     char  *commands1[] = {"set title \"Threshold vs N_Ratio\"", "set xrange[0:254]", "set yrange[0:18000]", "plot 'result1.dat' using 1:3 with lines", };
     char *commands3[] = {"set title \"Discriminative Index vs N_Ratio\"", "set xrange[0:6]", "set yrange[0:18000]", "plot 'result1.dat' using 2:3 with lines"};
	FILE *plot1,*plot2,*plot3;
	plot1 = popen("gnuplot -persistent", "w");
	plot2 = popen("gnuplot -persistent", "w");
	plot3 = popen("gnuplot -persistent", "w");
	for(i=0;i<4;i++)
    {
       	fprintf(plot1, "%s\n", commands1[i]);
       	fprintf(plot2, "%s\n", commands2[i]);
       	fprintf(plot3, "%s\n", commands3[i]);
    }
  }
  free(mtrx);
  return 0;
}
  
//Function to allocate the 2D matrix to store the data.
int** matrix( int row , int col ){
  int **a = (int **)malloc( row * sizeof(int*) );
  for(int i=0;i<row;i++)
    a[i] = (int *) malloc( col * sizeof(int) );
  return a;
}

//Function to choose no. of rows and cols according to file name
void which_file(int *row,int *col, char *file){
  if(file[0]=='1'){
    *row=198;
    *col=200;
  }
  else if(file[0]=='2'){
    *row=1200;
    *col=1920;
  }
  else{
    *row=10967;
    *col=10004;
  }
}
