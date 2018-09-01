#include <stdio.h>
#include <stdlib.h>
#include "bmprw.h"
#include "arnold.h"

int main()
{
	Bmp *pBmp,*pBmpAnr, *(*fun)(Bmp *);
	int i=0;
	char name[1024]="paint.bmp";	
	pBmp=readBmp(name);
	printf("%d", pBmp->bih.biBitCount);
	if(pBmp->bih.biBitCount==24)
		fun=anrTran24;
	else if(pBmp->bih.biBitCount==8)
		fun=anrTran8;
	for(i=1;i<1000;i++){
		pBmpAnr=fun(pBmp);
		sprintf(name, "paint%03d.bmp", i);
		writeBmp(name,pBmpAnr);
		free(pBmp);
		pBmp=pBmpAnr;
	}
	free(pBmpAnr);
	return 0;

}