#include <stdio.h>
#include <stdlib.h>

void rank(int *inputArray, int m)
{
    int i, j;
    int k;
    int temp;
    for(i=0;i<m-1;i++)
    {
        k=m-1-i;
        for(j=0;j<k;j++)
        {
            if(*(inputArray+j)>*(inputArray+j+1))
            {
                temp=*(inputArray+j+1);
                *(inputArray+j+1)=*(inputArray+j);
                *(inputArray+j)=temp;
            }
        }
    }
    for(i=0;i<=m-1;i++)
    {
        printf("%d\t", *(inputArray+i));
    }
    printf("\n");
}
