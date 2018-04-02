#include "image2file.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct tagBITMAPFILEHEADER {
        unsigned short    bfType;
        unsigned long   bfSize;
        unsigned short    bfReserved1;
        unsigned short    bfReserved2;
        unsigned long   bfOffBits;
} BITMAPFILEHEADER ;

typedef struct tagBITMAPINFOHEADER{
        unsigned long      biSize;
        long       biWidth;
        long       biHeight;
        unsigned short       biPlanes;
        unsigned short       biBitCount;
        unsigned long      biCompression;
        unsigned long      biSizeImage;
        long       biXPelsPerMeter;
        long       biYPelsPerMeter;
        unsigned long      biClrUsed;
        unsigned long      biClrImportant;
} BITMAPINFOHEADER ;



unsigned char * getGrayscaleImageFromBmp(char* filename , long* pWidth , long* pHeight)
{
    unsigned char * pPixel = NULL  ;
    long width , height ;
    FILE* fp  = NULL  ;
    int colors ;
    int offset2Pixel ;
    unsigned short bitsPerPixel ;
    unsigned char  (*pColorPalette)[4] ;
    unsigned char* pRow ;
    int bytesPerRow ;
    //BITMAPFILEHEADER bfi ;
    unsigned char bfi[14] ;
    BITMAPINFOHEADER bmi ;
    fp = fopen(filename , "rb") ;
    if( !fp )
        return NULL ; //NULL is zero
    fread(&bfi , 1 , sizeof(bfi) , fp ) ;
    fread(&bmi , 1 , sizeof(bmi) , fp ) ;
    width = bmi.biWidth ;
    height =  bmi.biHeight ;
    colors = bmi.biClrUsed ;
    if ( colors > 0) {
        pColorPalette = (unsigned char (*)[4])malloc( colors*4) ;
        if( !pColorPalette )
            goto end ;
        fread(pColorPalette , colors , 4 , fp  ) ;
    }
    offset2Pixel = 0 ;// bfi.bfOffBits ;
    if ( offset2Pixel == 0 ) {
        offset2Pixel = sizeof( bfi ) + sizeof(bmi ) + colors*4 ;
    }
    bitsPerPixel = bmi.biBitCount ;
    bytesPerRow = (bitsPerPixel*width /8 +3)/4*4 ;
    pRow = (unsigned char* ) malloc( bytesPerRow) ;
    if( !pRow ) {
        goto end ;
    }
    pPixel = (unsigned char*)malloc(width*height ) ;
    if( !pPixel )
        goto end ;
    switch ( bitsPerPixel ) {
        case 24:
            {
                unsigned char grayscale;
                int  col , row ;
                for( row = 0 ; row < height  ;row ++  ) {
                    fread(pRow , 1, bytesPerRow , fp  ) ;
                    for( col = 0 ; col  < width ; col ++  ) {
                        grayscale = 0.12*pRow[3*col];
                        grayscale = 0.59*pRow[3*col+1];
                        grayscale = 0.29*pRow[3*col+2];
                        pPixel[row*width+col] = grayscale ;
                    }
                }
            }
            break ;
        default:
            {
                printf("No support for bitsPerPixel = %d\n" , bitsPerPixel ) ;
                free ( pPixel ) ;
                pPixel = 0 ;
            }
     }
end :
    if( fp ) {
        fclose( fp ) ;
    }
    if( pColorPalette )
        free ( pColorPalette ) ;

    * pWidth = width ;
    * pHeight = height ;
    return pPixel ;
}


int saveGrayscaleImage2Bmp(char* filename , unsigned char* pPixel , long width , long height )
{
    FILE* fp  = NULL  ;
    int colors   ;
    unsigned char colorone[4] ;

    unsigned short bitsPerPixel ;
    unsigned char* pRow ;
    unsigned char pad[4] = {0};
    int bytesPerRow  ;
    int row ;
    unsigned long  offset2Pixel = 14+40+256*4 ;
    //BITMAPFILEHEADER bfi = {('B'<<8)|'M', sizeof(bfi), 0 ,0 ,0 } ;
    unsigned char bfi[14] = {'B','M' , 14 } ;
    bfi[14-1] = (offset2Pixel >> 3*8) &0xff;
    bfi[14-2] = (offset2Pixel >> 2*8) &0xff ;
    bfi[14-3] = (offset2Pixel >> 1*8) &0xff ;
    bfi[14-4] = (offset2Pixel >> 0) &0xff ;
    BITMAPINFOHEADER bmi = {
        sizeof(bmi) ,
        width ,
        height ,
        1,
        8,
        0,
        0 ,
        0,
        0,
        256,
        0} ;

    fp = fopen(filename , "wb") ;
    if( !fp )
        return SAVE_GRAY_FAIL;
    fwrite(&bfi , 1 , sizeof(bfi) , fp ) ;
    fwrite(&bmi , 1 , sizeof(bmi) , fp ) ;

    colorone[3] = 0 ;
    for( colors = 0 ; colors <= 255 ; colors ++  ) {
        colorone[0]=colorone[1]=colorone[2] = colors ;
        fwrite( colorone , 4 , 1 , fp  ) ;
    }
    bitsPerPixel = bmi.biBitCount ;
    bytesPerRow = (bitsPerPixel*width /8 +3)/4*4 ;
    pRow = (unsigned char* ) malloc( bytesPerRow) ;
    if( !pRow ) {
        goto end ;
    }
    for( row = 0 ; row < height  ; row ++  ) {
        pRow = pPixel + row * width  ;
        fwrite(pRow , 1, width  , fp  ) ;
        fwrite( pad , 1, bytesPerRow - width , fp  ) ;
    }
 end :
    if( fp ) {
        fclose( fp ) ;
    }

    return SAVE_GRAY_OK ;
}
