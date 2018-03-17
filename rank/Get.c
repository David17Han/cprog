#include <stdio.h>
#include <stdlib.h>

void Get(int array[],int p)
{
    int i;
    printf("Please input %d numbers.\n", p);
    for(i=0;i<p;i++)
    {
        scanf("%d", &array[i]);
    }
}
