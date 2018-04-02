#include <stdio.h>
#include <stdlib.h>

int BinSearch(int array[], int m)
{
    int target;
    int low=0, mid, high=m-1;
    int find=0;
    printf("Please input the number you want to search:");
    scanf("%d", &target);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(array[mid]==target)
        {
            printf("Number is found.\n");
            find=1;
            break;
        }
        else if(array[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(find==0)
    {
        printf("Not found.");
        mid=-1;
    }
    return mid;
}
