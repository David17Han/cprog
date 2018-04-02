#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "inputSample.h"
#define N 1024

double calculateStatistics(int *inputArray, int n, double *median, double *var);
void rank(int *inputArray, int m);

int main()
{
    int n;
    int array[N];
    double ave;
    double median;
    double var;
    double *p, *q;
    p=&median;
    q=&var;
    printf("Please input the number of your data:\n");
    scanf("%d", &n);
    sampleData(&array[0], n);
    ave=calculateStatistics(&array[0], n, p, q);
    printf("%f\n", ave);
    printf("%f\n", *q);
    printf("%f", *p);
    return 0;
}
