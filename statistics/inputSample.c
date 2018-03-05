#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inputSample.h"

/* p: array that store sample data
/* n: the number of sample data
/* median: pointer to bring back the  median £¨ÖÐÎ»Êý£©
/* var : pointer to bring back variance
/* return value: average value */
extern double calculateStatistic( int* p , int n , double * median , double *var ) ;


int sampleData( int *inputArray ,  int n  )
{
    FILE* fp ;
    int i = 0 ;
    int tmp ;
    if( n <= 1 ) //n-1 is the denominator when calculating variance
        return FAIL ;
    fp = fopen("E:\\sample.txt" , "wt") ;
    if(!fp)
        return FAIL ;
    srand( time(0) ) ;
    do {
        tmp = rand()%SAMPLE_VALUE_MAX;
        inputArray[i] = tmp  ;
        fprintf(fp,"%d\n" , tmp ) ;
        i ++ ;
    } while ( i < n ) ;
    fclose(fp) ;
    return SUCCESS ;
}


int main0()//can change to main to use this test routine.
{
    int inputA[100] ;
    int i = 0 , n ;
    double average , median , var ;
    printf("Please enter the sample number to input (1~100):\n");
    scanf("%d", &n ) ;
    sampleData( inputA , n ) ;
    do {
        printf("%d " , inputA[i]) ;
        i ++  ;
        if( i %20 == 0  )
            printf("\n") ;
    }while( i <n ) ;
    printf("\n") ;
    //average = calculateStatistic( inputA ,  n , & median , & var ) ;
    //printf("av=%f, med=%f ,var=%f\n" , average , median , var )  ;
    return 0;
}
