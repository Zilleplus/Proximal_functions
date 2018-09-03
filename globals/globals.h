#include <math.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



#ifndef real_t
    #define real_t double
#endif 

#ifndef SUCCESS
    #define SUCCESS 0
#endif 

#ifndef FAILURE
    #define FAILURE 1
#endif 

#ifndef LARGE
    #define LARGE 1e7
#endif 

#ifndef ABS
    #define ABS(x) fabs(x)
#endif 

#ifndef MACHINE_ACCURACY
    #define MACHINE_ACCURACY DBL_EPSILON
#endif 

#ifndef FALSE
    #define FALSE 0
#endif 

#ifndef TRUE
    #define TRUE 1
#endif

/**********SemiSmooth Newton Algorithmic parameters **********/

/* Maximum number of iterations for each method. */
#ifndef MAXITERS
    #define MAXITERS 100000
#endif 

/* Precision required in the stopping criteria, it is set very high to
   ensure that the problems are solved "exactly". */
#ifndef PREC
   #define PREC 1.0e-12
#endif

/* If a bracket interval becomes very narrow, assume that its mid
   point is the solution. */
#ifndef BRACKETPREC
    #define BRACKETPREC 2.2204460492503131e-16
#endif



/* Used to indicate an invalid value for a multiplier- Used in Newton method */
#ifndef INVALIDLAMBDA
    #define INVALIDLAMBDA DBL_MAX
#endif



/* Macro to compute the maximum and minimum between two values. */
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))


/********** Auxiliary macros **********/

/* Macro to print information while debugging. */
#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__);
#else
#define DEBUG_PRINT(...) {};
#endif


