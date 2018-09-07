#ifndef INDICATOR_BOX_HYPERPLANE_H
#define INDICATOR_BOX_HYPERPLANE_H

#include "../globals/globals.h"

struct indicator_intersection{
    unsigned int dimension;
    real_t lower_bound;
    real_t upper_bound;
    real_t inf;
    real_t hyperplane_rhs;
  
};


struct indicator_bin* init_indicator_intersection_hyperplane(\
    const unsigned int dimension_,const real_t lower_bound,const real_t upper_bound, const real_t hyperplane_rhs);


real_t prox_indicator_intersection_hyperplane(const struct indicator_intersection* data,real_t* input, real_t gamma);

#endif


