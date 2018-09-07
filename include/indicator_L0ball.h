#ifndef INDICATOR_L0BALL_H
#define INDICATOR_L0BALL_H

#include "../globals/globals.h"

struct indicator_L0ball{
    unsigned int* positions;
    unsigned int number_of_non_zero_elements;
    unsigned int dimension;
};

real_t prox_indicator_L0ball(const struct indicator_L0ball* data,real_t* input, real_t gamma);
struct indicator_L0ball* init_L0ball(const unsigned int dimension,const unsigned int number_of_non_zero_elements);



#endif
