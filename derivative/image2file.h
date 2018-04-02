

unsigned char * getGrayscaleImageFromBmp(char* filename , long* pWidth , long* pHeight) ;
#define SAVE_GRAY_OK    0
#define SAVE_GRAY_FAIL  -1
int saveGrayscaleImage2Bmp(char* filename , unsigned char* pPixel , long pWidth , long pHeight ) ;
