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


int testChangeAsendSortMain()
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
    changeAsendSort( a , n ) ;
    for( ins = 0 ; ins < n  ; ins ++ ) {
        printf("%d " , a[ins] ) ;
    }
    printf("\n") ;
    return 0 ;
}
