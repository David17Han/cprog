#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5000
#define PI 3.141592653
#define INTEGRALN 8000
typedef struct
{
	int n;
	double (*fx)(double x);
	double *an, *bn;
}fourierSeries;

fourierSeries *initFourierSeries(int n, double (*f)(double x))
{
	fourierSeries * p;
	int size=sizeof(fourierSeries)+2*(n+1)*sizeof(double);
	p=(fourierSeries*)malloc(size);
	if(p==NULL) 
		return p;
	p->n=n+1;
	p->fx=f;
	p->an=(double*)(p+1);
	p->bn=(p->an+n+1);
	return p;
}

double rectf(double x)
{
	while(x>PI)
	{
		x-=2*PI;
	}
	while(x<-PI)
	{
		x+=2*PI;
	}
	if(x<0) return (-1)*x;
	else return x;
}

double sqrf(double x)
{
	while(x>PI)
	{
		x-=2*PI;
	}
	while(x<-PI)
	{
		x+=2*PI;
	}
	return x*x;
} 


double integral(int n, double (*fx)(double x), double (*tri)(double ))
{
	double pace=PI/INTEGRALN, sum=0;
	int i;
	for(i=-INTEGRALN;i<INTEGRALN;i++)
	{
		double x = i*pace ;
		double y = fx(x);
		//printf("%f %f\n" , x ,y ) ;
		sum += y*tri(x*n)*pace;
	}
	return sum/PI;
}

void calcFourierCoeff(fourierSeries *p)
{
	int i=0;
	while(i<p->n)
	{
		p->an[i]=integral(i, p->fx,cos);
		p->bn[i]=integral(i, p->fx,sin);
		i++;
	}
}

double calcResult(fourierSeries *p, double x)
{
	double sum=0;
	int i;
	for(i=1;i<p->n;i++)
	{
		sum+=p->an[i]*cos(i*x);
		sum+=p->bn[i]*sin(i*x);
	}
	sum+=p->an[0]/2;
    return sum;
}

void dumpFourierSeriesCoeff(fourierSeries *p)
{
	FILE *fp;
	int i;
	fp=fopen("list2.csv", "wt");
	for(i=0;i<p->n;i++)
	{
		fprintf(fp, "%f,%f\n", p->an[i], p->bn[i]);
	}
	fclose(fp);
}

/*void takeFourierSeriesCoeff(fourierSeries *p)
{
	FILE *fp;
	int i;
	fp=fopen("list2.csv", "r");
	if(fp==NULL) printf("error\n");
	for(i=0;i<p->n;i++)
	{
		fscanf(fp, "%lf,%lf", &p->an[i], &p->bn[i]);
	}
	fclose(fp);
}*/

int main()
{
	double x=0, result;	
	int i=0;
	fourierSeries *pFourier =initFourierSeries(N,sqrf);
	calcFourierCoeff(pFourier );
	dumpFourierSeriesCoeff(pFourier);
	//takeFourierSeriesCoeff(pFourier);
	while ( x != -156 ) 
	{
		scanf("%lf", &x);
		result=calcResult(pFourier, x);
		printf("%f, %f\n",x , result);
	}
	free(pFourier);
	return 0;
}

