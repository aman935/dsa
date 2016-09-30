#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/resource.h>
int main(int argc, char *argv[])
{
  clock_t start = clock();
  int n, i, j;
  float beta;
  printf("Enter the value of n: ");
  scanf("%d", &n);
  printf("Enter the value of beta: ");
  scanf("%f", &beta);
  float a[n], b[n], d[n + 1], r[n + 1], theta[n + 1], E_theta[n + 1];
  float mid = (-2 * (n - 1) *(n - 1)) - beta;
  float k = (n - 1) * (n - 1);
  for (i = 0; i < n; i++) {
    if (i != n - 1) {
      a[i] =k;
      b[i - 1] = k;
    }
    d[i] = mid;
    r[i] = 0;
  }
  a[0] = 0;
  d[n - 1] = 1;
  b[n - 2] = -1;
  d[0] = 1;
  r[0] = 1;
  printf("\n");
  for(i = 0;i < n;i++ ){
    for (j = 0;j < n;j++) {
      if(i == j)
	k = d[i];
      else if(j == i - 1)
	k = b[j];
      else if(j == i + 1)
	k = a[j - 1];
      else k = 0;
      printf("%8.1f",k);
    }
    printf("\n");
  }
  for (i = 1; i <n - 1; i++) {
    d[i] = d[i] - (a[i - 1] * b[i]) / d[i - 1];
    r[i] = r[i] - (r[i - 1] * b[i]) / d[i - 1];
  }
  /* printf("\n"); */
  /* for(i = 0;i < n;i++ ){ */
  /*   for (j = 0;j < n;j++) { */
  /*     if(i == j) */
  /* 	k = d[i]; */
  /*     else if(j == i - 1) */
  /* 	k = b[j]; */
  /*     else if(j == i + 1) */
  /* 	k = a[j - 1]; */
  /*     else k = 0; */
  /*     printf("%8.1f",k); */
  /*   } */
  /*   printf("\n"); */

  theta[n - 1] = r[n - 1] / d[n - 1];
  for (i = n - 2; i >= 0; i-- ) {
    theta[i] = (r[i] - a[i] * theta[i + 1]) / d[i];
  }
  for (i = 0; i < n; i++) {
    E_theta[i] = cosh(sqrt(beta) * (1.0 - (double)((i * 1.0)/ n))) / cosh(sqrt(beta));
    // printf("%f\n", E_theta[i]);
  }

  double err = 0, val = 0;
  for (i = 0; i < n; i++) {
    val += (E_theta[i] - theta[i])*(E_theta[i] - theta[i]) ;
  }
  err = sqrt(val * (double)(1.0/n)) ;

  FILE * fp = fopen("ThomasThetas.txt", "w");
  FILE *fp1 = fopen("ThomasXTheta.txt", "w");
  FILE *fp2 = fopen("ThomasXETheta.txt", "w");
  FILE *fp3 = fopen("ThomasNErr.txt", "a"); 
  for (i = 0; i < n; i++) {
    fprintf(fp, "%f \t%f\n", theta[i], E_theta[i]);
    fprintf(fp1,"%f\t%f\n", (i * 1.0)/ n,theta[i]);
    fprintf(fp2,"%f\t%f\n", (i * 1.0)/ n,E_theta[i]);
  }
  fprintf(fp3,"%d\t%f\n", n,err);
  fclose(fp1);
  fclose(fp);
  fclose(fp2);
  fclose(fp3);
  char *commands2[] = {"set title \"Theta vs Theta_Exact\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'ThomasThetas.txt' using 1:2 with lines"};
  char *commands1[] = {"set title \"x* vs Theta\"", "set xrange[0:1]", "set yrange[0:1]", "plot 'ThomasXTheta.txt' using 1:2 with lines, 'ThomasXETheta.txt' using 1:2 with lines"};
  char *commands4[] = {"set title \"n vs Error\"", "set xrange[0:100]", "set yrange[0:0.05]", "plot 'ThomasNErr.txt' using 1:2 with lines"};
  
  FILE *plot10,*plot20,*plot30,*plot40;
  plot10 = popen("gnuplot -persistent", "w");
  plot20 = popen("gnuplot -persistent", "w");
  plot40 = popen("gnuplot -persistent", "w");
  for(i=0;i<4;i++)
    {
      fprintf(plot10, "%s\n", commands1[i]);
      fprintf(plot20, "%s\n", commands2[i]);
      fprintf(plot40, "%s\n", commands4[i]);
    }
  clock_t end = clock();
  double ti = end - start;
  ti /= CLOCKS_PER_SEC;
  printf("\nMemory used in Thomas' Algorithm: %d Bytes\n",4 * (5 * n + 9));
  printf("Time taken is: %lf\n", ti);
  return 0;
}
