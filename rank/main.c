#include <stdio.h>
#include <stdlib.h>
#define N 15
void ChangeSort(int array[], int m);
void SelectionSort(int array[],int m);
void BubbleSort(int array[],int m);
int BinSearch(int array[],int m);
void Get(int array[],int p);

int main()
{
    int choice;
    int array[N];
    int n;
    int ret=1;
    printf("Please choose your way to rank.\n1.change\n2.selection\n3.bubble\n");
    scanf("%d", &choice);
    printf("Please input the amount of numbers you want to rank:(No more than 15 numbers)");
    scanf("%d", &n);
    if(choice==1 && n>0 && n<=N)
    {
        Get(array, n);
        ChangeSort(array, n);
    }
    else if(choice==2 && n>0 && n<=N)
    {
        Get(array, n);
        SelectionSort(array, n);
    }
    else if(choice==3 && n>0 && n<=N)
    {
        Get(array, n);
        BubbleSort(array, n);
    }
    else
    {
        printf("Input error!\n");
        ret=0;
    }
    if(ret!=0)
    {
        int index;
        index=BinSearch(array, n);
        if(index!=-1)
        {
            printf("The target number is NO.%d.\n", index+1);
        }
    }
    return 0;
}
