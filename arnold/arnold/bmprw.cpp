#include "bmprw.h"
#include <stdlib.h>
#include <stdio.h>

Bmp* readBmp(char *filename)
{
	Bmp *pBmp;
	int total;
	FILE *fp;
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	fp=fopen(filename, "rb");
	fread(&bfh, 14, 1, fp);
	fread(&bih, 40, 1, fp);
	if(bih.biBitCount==24)
		total=(bih.biWidth*3+3)/4*4*bih.biHeight;
	else if(bih.biBitCount==8)
		total=(bih.biWidth+3)/4*4*bih.biHeight;
	bih.biSizeImage=total;
	pBmp=(Bmp*)malloc(sizeof(Bmp)+total);
	pBmp->bfh=bfh;
	pBmp->bih=bih;
	pBmp->pPix=(unsigned char *)(pBmp+1);
	fseek(fp, bfh.bfOffBits, SEEK_SET);
	fread(pBmp->pPix, total, 1, fp);
	fclose(fp);
	return pBmp;
}

void writeBmp(char *filename, Bmp *pBmp)
{
	FILE *fp;
	int total;
	total=(pBmp->bih.biWidth*3+3)/4*4*pBmp->bih.biHeight;
	fp=fopen(filename,"wb");
	fwrite(&pBmp->bfh,14,1,fp);
	fwrite(&pBmp->bih,40,1,fp);
	fwrite(pBmp->pPix,total,1,fp);
	fclose(fp);
}