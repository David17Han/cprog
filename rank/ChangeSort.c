#include <stdio.h>
#include <stdlib.h>

void ChangeSort(int array[], int m)
{
    int i, j;
    int temp;
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(array[i]>array[j])
            {
                temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
    for(i=0;i<=m-1;i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
