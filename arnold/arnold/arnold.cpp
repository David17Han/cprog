#include <stdio.h>
#include <stdlib.h>
#include "bmprw.h"

Bmp *anrTran24(Bmp *pSrc)
{
	Bmp *pTarg;
	int x,y;
	int nx,ny;
	unsigned char *ps,*pt, *pLine,*pnew;
	int bytesPerLine;
	pTarg=(Bmp *)malloc(sizeof(Bmp)+pSrc->bih.biSizeImage);
	pTarg->bfh=pSrc->bfh;
	pTarg->bih=pSrc->bih;
	bytesPerLine=(pSrc->bih.biWidth*3+3)/4*4;
	pTarg->pPix=(unsigned char *)(pTarg+1);
	ps=pSrc->pPix;
	pt=pTarg->pPix;
	pLine=ps;
	for(y=0;y<pSrc->bih.biHeight;y++)
	{
		for(x=0;x<pSrc->bih.biWidth;x++)
		{
			nx=(x+y)%pSrc->bih.biWidth;
			ny=(x+2*y)%pSrc->bih.biHeight;
			pnew=pt+ny*bytesPerLine+nx*3;
			pnew[0]=pLine[x*3+0];
			pnew[1]=pLine[x*3+1];
			pnew[2]=pLine[x*3+2];
		}
		pLine+=bytesPerLine;
	}
	return pTarg;
}

Bmp *anrTran8(Bmp *pSrc)
{
	Bmp *pTarg;
	int x,y;
	int nx,ny;
	unsigned char *ps,*pt, *pLine,*pnew;
	int bytesPerLine;
	pTarg=(Bmp *)malloc(sizeof(Bmp)+pSrc->bih.biSizeImage);
	pTarg->bfh=pSrc->bfh;
	pTarg->bih=pSrc->bih;
	bytesPerLine=(pSrc->bih.biWidth+3)/4*4;
	pTarg->pPix=(unsigned char *)(pTarg+1);
	ps=pSrc->pPix;
	pt=pTarg->pPix;
	pLine=ps;
	for(y=0;y<pSrc->bih.biHeight;y++)
	{
		for(x=0;x<pSrc->bih.biWidth;x++)
		{
			nx=(x+y)%pSrc->bih.biWidth;
			ny=(x+2*y)%pSrc->bih.biHeight;
			pnew=pt+ny*bytesPerLine+nx*3;
			pnew[0]=pLine[x];
		}
		pLine+=bytesPerLine;
	}
	return pTarg;
}