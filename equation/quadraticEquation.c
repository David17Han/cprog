#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x1 , x2 ;
int solutionNum ;
int solveQuadraticEquation( double a , double b , double c)
{
    double delta ;
    solutionNum = 0 ;
    delta = b*b-4*a*c ;
    if( delta < 0 ){
        solutionNum = 0 ;
    }else if( delta == 0 ){
        solutionNum = 1 ;
    }else {
        solutionNum = 2 ;
    }
    x1=(-b-sqrt(delta))/2;
    x2 =(-b+sqrt(delta))/2;
    return solutionNum ;
}
double getQuadraticEquationSolution()
{
    double x = 0 ;
    switch( solutionNum  ) {
        case 2:
            x = x1 ;
            solutionNum -- ;
            break ;
        case 1 :
            x = x2 ;
            solutionNum -- ;
            break ;
        default :
            printf("error\n") ;
    }
    return x ;
}

/*
int main()
{
    double a,b,c ;
    int solNum ;
    scanf("%lf%lf%lf", &a, &b ,&c ) ;
    solNum = solveQuadraticEquation( a ,b ,c) ;
    if( solNum == 2 ) {
        double x1 , x2 ;
        x1 = getQuadraticEquationSolution() ;
        x2 = getQuadraticEquationSolution() ;
        printf("Solution of (%.2f,%.2f,%.2f) is %.2f,%.2f\n" , a,b,c,x1,x2) ;
    }else if( solNum == 1 ) {
        double x1  ;
        x1 = getQuadraticEquationSolution() ;
        printf("Solution of Quadratic equation(%.2f,%.2f,%.2f) is %.2f\n" , a,b,c,x1) ;
    }else {
        printf("Solution of Quadratic equation(%.2f,%.2f,%.2f) has no solution \n" , a,b,c) ;
    }

    printf("end of main\n");
    return 0;
}
*/
