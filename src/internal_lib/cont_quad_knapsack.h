/*
 * Module Name: cont_quad_knapsack
 *
 * Description: Implements the semismooth Newton method described in
 *     the manuscript 
 * 
 *     R. Cominetti, W. F. Mascarenhas, and Paulo J. S. Silva. "A
 *     Newton method for the continuous quadratic knapsack problem". 
 *
 *     It also implements a simple structure to hold the problems.
 *
 * Copyright: Paulo J. S. Silva <pjssilva@gmail.com> 2012.
 */

/* 
 * Structure to describe a continuous quadratic knapsack problem in the form
 * 
 * min  1/2 x'Dx - a'x
 * s.t. b'x = r
 *      low <= x <= up,
 *
 * where D is a positive diagonal matrix.
 *
 * IMPORTANT: As in the manuscript the code assumes that b > 0. It is
 * the user responsibility to change the problem to fit this format.
 */
typedef struct cqk_problem {
    unsigned n;           /* Dimension of the problem. */
    double *d;   /* D positive diagonal (D = diag(d)). */
    double *a;   /* The a in the objective funtion definition. */
                          /* If the problem is interpreted as projection */
                          /* in the norm induced by D, the point being */  
                          /* projected is D^-1a. */
    double *b;   /* Slopes (positive) that define the plane. */
    double r;             /* Righthand side of the plane equation. */
    double *low; /* lower and */
    double *up;  /* upper bounds for the constraints. */
} cqk_problem;

/********** Interface of a cqn_structure *********/

/*
 * Function Name: allocate_cqk_problem
 *
 * Description: Allocate the memory necessary hold a CQN problem in
 *     dimension n.
 *
 * Input:
 *     unsigned n: The dimension of the problem.
 * 
 * Output: cqk_problem *p: pointer to the cqk_problem whose memory is
 *     being allocated.
 */
void allocate_cqk_problem(unsigned n, cqk_problem *p);

/*
 * Function Name: free_cqk_problem
 *
 * Description: Free the memory associated to a cqk_problem.
 *
 * Input/Output: 
 *     cqk_problem *p: at entry a cqk_problem with allocated
 *         memory, at output all the memory will be freed and the pointers
 *         in the cqk_problem structure will point to NULL.
 */
void free_cqk_problem(cqk_problem *p);

/********** Interface for the Newton method **********/
/*
 * Function Name: initial_multiplier
 *
 * Description: Estimate an initial multiplier from an approximate
 *     solution.
 *
 * Input:
 *     cqk_problem *restrict p: description of the cont. quad. knapsack.
 *     double *restrict x: approximate solution.
 *
 * Output:
 *     double *restrict slopes: slopes of the terms that define the phi 
 *         function.
 *     double *restrict sum_slopes: sum of all slopes.
 *     unsigned *restrict ind: indexes of the active variables that are 
 *         initialized as all. 
 * 
 * Return value: the desired estimate.
 */
double __initial_multiplier(cqk_problem *p, double *x,
                          double *slopes, double *sum_slopes,
                          unsigned *ind);
/*
 * Function Name: newton
 *
 * Description: Newton method for the cont. quad. knapsack problem.
 *
 * Input:
 *     cqk_problem *restrict p: the problem description.
 *     double *x0: used it to estimate the initial mulplier if not
 *         NULL.
 * 
 * Output:
 *     double *x: solution obtained.
 * 
 * Return value: the number of iterations required to compute the
 *     solution or -1 in case of failure.
 */
int newton(cqk_problem *p, double *x0, double *x);

/* Structure to hold a bracket interval */
typedef struct {
    double neg_lambda; /* Largest multiplier to the left of the zero */
    double pos_lambda; /* Smallest multiplier to the right of the zero */
    double negPhi;     /* Value of phi at neg_lambda  */
    double posPhi;     /* Value of phi at pos_lambda    */
} bracket;



