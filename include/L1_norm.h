#ifndef L1_NORM_H
#define L1_NORM_H

#include "../globals/globals.h"

struct L1_norm{
    real_t mu;
    unsigned int dimension;
};

struct L1_norm* init_L1_norm(const unsigned int dimension,const real_t mu);
real_t proxg_L1_norm(const struct L1_norm* data,real_t* input, real_t gamma);

#endif
