
/* solve equation ax^2+bx+c=0, return the solution number:0,1 or 2 */
extern int solveQuadraticEquation( double a , double b , double c) ;
/* Get the solution one by one after calling solveQuadraticEquation
   you should get the solution like the following :
   int soln =  solveQuadraticEquation( 1.0,-3.0,2.0 ) ;
   if ( soln == 2 ) {
        double x1 = getQuadraticEquationSolution() ;
        double x2 = getQuadraticEquationSolution() ;
   }else if( soln == 1 ) {
        double x1 = getQuadraticEquationSolution() ;
   }else {
        //no solution
   }
*/
extern double getQuadraticEquationSolution() ;
