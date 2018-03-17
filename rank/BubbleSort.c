#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int array[], int m)
{
    int i, j;
    int k;
    int temp;
    for(i=0;i<m-1;i++)
    {
        k=m-1-i;
        for(j=0;j<k;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }
    for(i=0;i<=m-1;i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
