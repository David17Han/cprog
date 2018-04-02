#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int array[], int m)
{
    int i, j;
    int k;
    int temp;
    for(i=0;i<m-1;i++)
    {
        k=i;
        for(j=i+1;j<m;j++)
        {
            if(array[k]>array[j])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp=array[k];
            array[k]=array[i];
            array[i]=temp;
        }
    }
    for(i=0;i<=m-1;i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
