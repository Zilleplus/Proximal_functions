#include "../globals/globals.h"
#include "../include/indicator_intersection.h"
#include <stdlib.h>
#include "internal_lib/cont_quad_knapsack.h"


//box-halfspace ingredients
struct indicator_intersection* init_indicator_intersection_hyperplane(\
    const unsigned int dimension, const struct problem){

    struct indicator_intersection* data = malloc(sizeof(struct indicator_intersection));
    if(data==NULL) return NULL;

    data->dimension=dimension;
    allocate_cqk_problem(unsigned dimension, cqk_problem *p);
    data->problem = p;
	
    return data;
}


real_t prox_indicator_intersection_hyperplane(const struct indicator_intersection* data, real_t* input, real_t gamma){
    real_t g=0.*gamma; /* initialize the value of function at prox point  */
    
    
    newton(cqk_problem *p, NULL, double *input);
    return g;
}




