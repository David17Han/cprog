#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#pragma warning(disable:4996)
int main()
{
	double n;
	int a;
	char s[20]={0}, s1[11]={0};
	scanf("%lf", &n);
	a=(int)n;
	testIntMain(a,s);
	n=n-a;
	testDoubleMain(n,s1);
	strcat(s,".");
	strcat(s,s1);
	printf("%s\n", s);
	return 0;
}