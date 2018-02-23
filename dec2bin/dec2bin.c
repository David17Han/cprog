#include <stdio.h>
#include <stdlib.h>

#define MAXS 1024
static int stackTrunk[MAXS] ;
static int top ;
#define OK 0
#define ERR -1
void createStack()
{
    top = -1 ;
}

int push(int elem)
{
    if( top >= MAXS )
        return ERR ;
    top ++ ;
    stackTrunk[top] = elem ;
    return OK ;
}

int pop(int err[])
{
    int ret = -1 ;
    err[0] = OK ;
    if( top < 0 ) {
        err[0] = ERR ;
    }else {
        ret = stackTrunk[top] ;
        top -- ;
    }
    return ret ;
}
int main()
{
    int dec , bin  ;
    int err[1] ;
    scanf("%d" , &dec) ;
    createStack();
    while( dec ) {
        push( dec%2 ) ;
        dec >>= 1 ;
    }
    //err[0] = OK ;
    while ( 1 ) {
        bin = pop( err ) ;
        if( err[0] == OK ) {
            printf("%d" , bin ) ;
        }else {
            break ;
        }
    }
    printf("\n") ;

    return 0;
}
