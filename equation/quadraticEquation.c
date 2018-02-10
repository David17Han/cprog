#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x ;
double x1 , x2 ;//solution of equation
int solutionNum ;

/* solve equation ax^2+bx+c=0, return the solution number:0 or 2 */
int solveQuadraticEquation( double a , double b , double c)
{
    double delta ;
    solutionNum = 0 ;
    delta = b*b-4*a*c ;
    if( delta < 0 ){
        solutionNum = 0 ;
    }else {
        solutionNum = 2 ;
        x1=(-b-sqrt(delta))/(2*a);
        x2 =(-b+sqrt(delta))/(2*a);
    }
    return solutionNum ;
}
/* Get the solution one by one after calling solveQuadraticEquation
   you should get the solution like the following :
   int soln =  solveQuadraticEquation( 1.0,-3.0,2.0 ) ;
   if ( soln == 2 ) {
        double x1 = getQuadraticEquationSolution(1) ;
        double x2 = getQuadraticEquationSolution(2) ;
   }else {
        //no solution
   }
*/
double getQuadraticEquationSolution(int solNo)
{
    double x = 0 ;
    if( solutionNum != 2 )
        printf("error to call me!\n") ;
    switch( solNo ) {
        case 1:
            x = x1 ;
            break ;
        case 2 :
            x = x2 ;
            break ;
        default :
            printf("error\n") ;
    }
    return x ;
}


