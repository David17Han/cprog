#include <stdio.h>
#include "image2file.h"
#include <stdlib.h>

int main()
{
    char nameSrc[1024] ={0} ;
    char nameDst[1024] ={0} ;
    unsigned char* pPixel = 0 ;
    long width , height ;
    int ret ;
    printf( "Enter src name and dst name :\n"  ) ;
    scanf("%s%s", nameSrc, nameDst ) ;
    pPixel = getGrayscaleImageFromBmp( nameSrc  , &width , &height) ;
    if( !pPixel ) {
        printf("getting grayscale image fails\n") ;
        goto end ;
    }
    ret = saveGrayscaleImage2Bmp( nameDst , pPixel  ,  width ,  height ) ;
    if( ret == SAVE_GRAY_OK )
        printf("Saving grayscale image ok\n") ;
    else
        printf("Saving grayscale image fails\n") ;
    if( pPixel != 0  )
        free( pPixel ) ;
end :
    return 0;
}
