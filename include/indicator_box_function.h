#ifndef CONSTRAINT_FUNCTIONS_H
#define CONSTRAINT_FUNCTIONS_H

#include "../globals/globals.h"

struct indicator_box_square_function{
    unsigned int dimension;
    real_t lower_bound;
    real_t upper_bound;
    real_t inf;
};

real_t proxg_indicator_box_square_function(const struct indicator_box_square_function* data,real_t* input);

struct indicator_box_square_function* constraint_functions_init_box(\
    const unsigned int dimension_,const real_t lower_bound,const real_t upper_bound,const real_t value_inf);

#endif