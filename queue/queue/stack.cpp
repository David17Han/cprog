#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#pragma warning(disable:4996)

Stack* initStack()
{
	Stack *stack;
	stack=(Stack *)malloc(sizeof(Stack));
	stack->top=-1;
	return stack;
}

void push(Stack * stack, char c)
{
	stack->top++;
	stack->pool[stack->top]=c;
}

char pop(Stack * stack)
{
	char c=stack->pool[stack->top];
	stack->top--;
	return c;
}

int isStackEmpty(Stack *stack)
{
	if(stack->top==-1) return EMPTY;
	else return NOTEMPTY;
}

char* testIntMain(unsigned a,char * s)
{
	char c;
	int i=0;
	Stack *stack;
	stack=initStack();
	while(a!=0)
	{
		c=a%10+'0';
		a=a/10;
		push(stack,c);
	}
	while(!isStackEmpty(stack))
	{
		s[i]=pop(stack);
		i++;
	}
	printf("%s\n", s);
	return s;
}