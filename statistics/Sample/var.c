#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1024

void rank(int *inputArray, int m);
double calculateStatistics(int *inputArray, int n, double *median, double *var)
{
    int i;
    int sum=0;
    double totalvar;
    double temp;
    for(i=0;i<n;i++)
    {
        sum=sum+*(inputArray+i);
    }
    for(i=0;i<n;i++)
    {
        totalvar=totalvar+pow(*(inputArray+i)-(double)sum/n,2);
    }
    temp=(double)totalvar/n;
    *var=temp;
    rank(inputArray, n);
    i=(n-1)/2;
    if(n%2==0)
    {
        *median=(double)(*(inputArray+i)+*(inputArray+i+1))/2;
    }
    else
    {
        *median=*(inputArray+i);
    }
    return (double)sum/n;
}
