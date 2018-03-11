#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define FAIL -1

int factorial(int n, unsigned int *p);

int main()
{
    int n;
    int ret;
    unsigned int result;
    printf("Please input a number:\n");
    scanf("%d", &n);
    ret=factorial(n, &result);
    if(ret==OK)
    {
        printf("%u\n", result);
    }
    else
    {
        printf("error\n");
    }
    return 0;
}

/*Calculating factorial
  n is the number to calculate factorial
  p is the pointer to result
  return value:OK means successful
               FAIL means failing*/
int factorial(int n, unsigned int *p)
{
    int i;
    unsigned int test=1;
    *p=1;
    for(i=1;i<=n;i++)
    {
        *p=*p*i;
        if(*p<test)
        {
            return FAIL;
        }
        test=*p;
    }
    return OK;
}
