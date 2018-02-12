#include <stdio.h>
#include <stdlib.h>


void changeAsendSort( int data[] , int n )
{
    int i , j ;
    for( i = 0 ; i <= n-2 ; i ++ ) {
        for( j = i ;j <= n-1 ; j ++ ) {
            if( data[i] > data[j] ) {
                int tmp = data[i] ;
                data[i] = data[j] ;
                data[j] = tmp ;
            }
        }
    }
}

void selectionAsendSort( int data[] , int n )
{
    int i , j  , k ;
    int tmp;
    for( i = 0 ; i <= n-2 ; i ++ ) {
        k = i ;
        for( j = i+1 ;j <= n-1 ; j ++ ) {
            if( data[k] > data[j] ) {
                k = j ;
            }
        }
        if( k != i ) {
            tmp = data[i] ;
            data[i]= data[k] ;
            data[k] = tmp ;
        }
    }
}

void bubbleAsendSort( int data[] , int n )
{
    int i , j  ;
    int tmp;
    for( i = 0 ; i <= n-2 ; i ++ ) {
        for( j = 1 ;j <= n-i ; j ++ ) {
            if( data[j] < data[j-1] ) {
                tmp = data[j] ;
                data[j] = data[j-1];
                data[j-1] = tmp  ;
            }
        }
    }
}

int testSortMain( void (*Sort)( int data[] , int n ) )
{
    int n = 0 , a[1024] ;
    int ins ;
    do {
        ins = scanf("%d" , a + n );
        //n ++ ;
    } while ( (ins > 0) && (++n) ) ;
    for( ins = 0 ; ins < n  ; ins ++ ) {
        printf("%d " , a[ins] ) ;
    }
    printf("\n") ;
    (*Sort)( a , n ) ;
    for( ins = 0 ; ins < n  ; ins ++ ) {
        printf("%d " , a[ins] ) ;
    }
    printf("\n") ;
    return 0 ;
}


int main()
{
    int i  ;
    void (*Sort[])( int data[] , int n ) = {changeAsendSort , selectionAsendSort , bubbleAsendSort  };
    printf("Hello world!\n");
    for ( i = 0 ; i < sizeof(Sort)/sizeof(Sort[0]) ; i ++  ) {
        printf("%d:\n" , i );
        testSortMain( Sort[i]) ;
    }
    return 0;
}
