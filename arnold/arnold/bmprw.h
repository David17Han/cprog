#ifndef BMPRW_H
#define BMPRW_H
typedef struct tagBITMAPFILEHEADER {
        unsigned short    bfType;
        unsigned long   bfSize;
        unsigned short    bfReserved1;
        unsigned short    bfReserved2;
        unsigned long   bfOffBits;
} BITMAPFILEHEADER;
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
} BITMAPINFOHEADER;
typedef struct Bmp {
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	unsigned char  * pPix;
}Bmp;

Bmp* readBmp(char *filename);
void writeBmp(char *filename, Bmp *pBmp);
#endif