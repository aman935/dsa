#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/resource.h>
int main(int argc, char *argv[])
{
  clock_t start = clock();
  int n, i, j;
  float beta, multiple, prev_theta;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  printf("Enter the value of beta: ");
  scanf("%f", &beta);
  float a[n - 1], b[n - 1], d[n] , matrix[n][n + 1], theta[n], E_theta[n];
  float mid = (-2 * (n - 1) *(n - 1)) - beta;
  int k = (n - 1) * (n - 1);
  for (i = 0; i < n; i++) {
    if (i != n - 1) {
      a[i] =k;
      b[i - 1] = k;
    }
    d[i] = mid;
    matrix[i][n] = 0;
  }
  a[0] = 0;
  d[n - 1] = 1;
  b[n - 2] = -1;
  d[0] = 1;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if(i == j)
	matrix[i][j] = d[i];
      else if(j == i + 1) {
	matrix[i][j] = a[j];
      }
      else if (j == i - 1) {
	matrix[i][j] = b[j];
      }
      else matrix[i][j] = 0;
    }
  }
  matrix[0][1] = 0;
  matrix[0][n] = 1;
  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j <= n; j++) {
      printf("%8.1f ", matrix[i][j]) ;
    }
    printf("|%8.1f", matrix[i][n]);
  }
  /* loop for the generation of upper triangular matrix*/
  for(j=0; j<n; j++)
    {
      for(i=0; i<n; i++)
        {
	  if(i>j)
            {
	      multiple=matrix[i][j]/matrix[j][j];
	      for(k=0; k <= n; k++)
		{
		  matrix[i][k]=matrix[i][k]-multiple*matrix[j][k];
		}
	    }
	}
    }
  /* For finding values of theta by back substitution */
  theta[n - 1]=matrix[n - 1][n]/matrix[n - 1][n - 1];
  float sum=0.0;
  for(i=n-2; i >= 0; i--)
    {
      sum=0;
      for(j=i+1; j<n; j++)
	{
	  sum += matrix[i][j]*theta[j];
	}
      theta[i]=(matrix[i][n]-sum)/matrix[i][i];
    }
  /* printf("\n"); */
  /* for (i = 0; i < n; i++) { */
  /*   printf("\n"); */
  /*   for (j = 0; j < n; j++) { */
  /*     printf("%8.1f ", matrix[i][j]) ; */
  /*   } */
  /*   printf("|%8.6f", matrix[i][n]); */
  /* } */
  for (i = 0; i < n; i++) {
    E_theta[i] = cosh(sqrt(beta) * (1.0 - (double)((i * 1.0)/ n))) / cosh(sqrt(beta));
    // printf("%f\n", E_theta[i]);
  }
  double err = 0, val = 0;
  for (i = 0; i < n; i++) {
    val += (E_theta[i] - theta[i])*(E_theta[i] - theta[i]) ;
  }
  err = sqrt(val * (double)(1.0/n)) ;
		
  FILE * fp = fopen("GaussThetas.txt", "w");
  FILE *fp1 = fopen("GaussXTheta.txt", "w");
  FILE *fp2 = fopen("GaussXETheta.txt", "w");
  FILE *fp3 = fopen("GaussNErr.txt", "a"); 
  for (i = 0; i < n; i++) {
    fprintf(fp, "%f \t%f\n", theta[i], E_theta[i]);
    fprintf(fp1,"%f\t%f\n", ((i + 1)* 1.0)/ n,theta[i]);
    fprintf(fp2,"%f\t%f\n", ((i + 1)* 1.0)/ n,E_theta[i]);
  }
  
  fprintf(fp3,"%d\t%f\n", n,err);
  char *commands2[] = {"set title \"Theta vs Theta_Exact\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'GaussThetas.txt' using 1:2 with lines"};
  char *commands1[] = {"set title \"x* vs Theta\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'GaussXTheta.txt' using 1:2 with lines,'GaussXETheta.txt' using 1:2 with lines"};
  char *commands4[] = {"set title \"n vs Error\"", "set xrange[0:50]", "set yrange[0:0.05]", "plot 'GaussNErr.txt' using 1:2 with lines"};
  
  FILE *plot1,*plot2,*plot3, *plot4;
  plot1 = popen("gnuplot -persistent", "w");
  plot2 = popen("gnuplot -persistent", "w");
  plot4 = popen("gnuplot -persistent", "w");
  for(i=0;i<4;i++)
    {
      fprintf(plot1, "%s\n", commands1[i]);
      fprintf(plot2, "%s\n", commands2[i]);
      fprintf(plot4, "%s\n", commands4[i]);
    }
  clock_t end = clock();
  double ti = end - start;
  ti /= CLOCKS_PER_SEC;
  printf("\nMemory used in Gauss' Elimination Method: %d Bytes\n",4 * ((5 * n + 14) + n * (n + 1)));
  printf("Time taken is: %lf\n", ti);
  return 0;
}

