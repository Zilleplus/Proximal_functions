/*
 * Module Name: synthetic_benchmark
 *
 * Description: Implements a set of synthetically generated random
 *     tests for methods to solve continuous quadratic knapsack
 *     problems. The first group of tests are described in Kiwiel's
 *     papers, like for example
 *
 *     Kiwiel KC. Variable Fixing Algorithms for the Continuous
 *     Quadratic Knapsack Problem. Journal of Optimization Theory and
 *     Applications. 2008;136(3):445-458. Available at:
 *     http://www.springerlink.com/index/10.1007/s10957-007-9317-7.
 *
 *     We also implement a test described by Dai and Fletcher that
 *     should capture the structure of some real world multicommodity
 *     network flow and logistics in the paper
 *
 *     Dai Y-H, Fletcher R. New algorithms for singly linearly
 *     constrained quadratic programs subject to lower and upper
 *     bounds. Mathematical Programming. 2005;106(3):403-421. Available
 *     at: http://www.springerlink.com/index/10.1007/s10107-005-0595-2.
 *
 * Copyright: Paulo J. S. Silva <pjssilva@gmail.com> 2012.
 */
#include "../globals/globals.h"
#include "../src/internal_lib/cont_quad_knapsack.h"



/*
 * Function Name: generate_infeasible_problem
 *
 * Description: Create a test instace for the projection problems
 *     that is infeasible
 *
 * Input: 
 *     n: dimension of the problem.
 *
 * Output:
 *     cqk_problem *restrict p: a infeasible problem.
 */
static void __generate_infeasible_problem(unsigned n, cqk_problem* p) { 
    
    allocate_cqk_problem(n, p);
    p->r = -1.0;
    unsigned int i;
    for (i = 0; i < n; ++i)
    {
        p->d[i] = 1.0;
        p->b[i] = 1.0 + 0.5*(((double) rand()) / RAND_MAX - 0.5);
        p->a[i] = 1.0;
        p->low[i] = 0.0;
        p->up[i] = DBL_MAX;
    }
}

/*
 * Function Name: generate_infeasible_problem2
 *
 * Description: Create a test instace for the projection problems
 *     that is infeasible
 *
 * Input: 
 *     n: dimension of the problem.
 *
 * Output:
 *     cqk_problem *restrict p: a infeasible problem.
 */
static void __generate_infeasible_problem2(unsigned n, cqk_problem* p) { 
    
    allocate_cqk_problem(n, p);
    p->r = -1.0;
    unsigned int i;
    for (i = 0; i < n; ++i)
    {
        p->d[i] = 1.0;
        p->b[i] = -1.0 + 0.5*(((double) rand()) / RAND_MAX - 0.5);
        p->a[i] = 1.0;
        p->low[i] = -DBL_MAX;
        p->up[i] = 0.0;
    }
}

/*
 * Function Name: main
 *
 * Description: run the test and warns if infeasibility is not detected.
 *
 * Usage: infeasible <problem dimension> 
 *
 * Input:
 *     int argc: number of command line paramters.
 *     char *argv[]: command line paramters.
 */
int main(int argc, char *argv[]) {
    unsigned n;         /* Problem dimension */

    /* Get the problem dimensions and define number of test
       repetitions. */
    if (argc != 2 || (n = atoi(argv[1])) <= 0 ) {
        fprintf(stderr, "Usage: infeasible <problem dimension>\n");
        exit(1);
    }

    /* Initialize the random number generator with known seed so that
       the same 'random' problems are generated always. */
    srand(1);

    /* Allocate solution vector */
    double *x = (double *) malloc(n*sizeof(double));

    /* Generate problem data */
    cqk_problem p;
    __generate_infeasible_problem(n, &p);

    /* Solve first problem */
    int status = newton(&p, NULL, x);
    if (status != -2) 
        printf("Infeasibility not detected! Status %d.\n", status);
    
    /* Generate problem data */
    __generate_infeasible_problem2(n, &p);

    /* Solve second problem */
    status = newton(&p, NULL, x);
    if (status != -2) 
        printf("Infeasibility not detected! Status %d.\n", status);
    
    free(x);
    free_cqk_problem(&p);
    return 0;
}
