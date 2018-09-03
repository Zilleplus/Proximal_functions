#include "../globals/globals.h"
#include "../include/one_norm.h"
#include<stdlib.h>



struct one_norm* init_one_norm(const unsigned int dimension,const real_t mu){
    struct one_norm* data = malloc(sizeof(struct one_norm));
    if(data==NULL) return NULL;

    data->dimension=dimension;
    data->mu=mu;


    int *cache;
    double sum;

    cache = (real_t*)malloc(data->dimension*sizeof(real_t));
    data->cache = cache;
    data->sum  = 0;
    free(cache);

    return data;
}

static real_t sign_x(real_t x) { return x<0 ? -1 : x>0 ? 1 : x;}

real_t  prox_one_norm(const struct one_norm* data, real_t* input, real_t gamma){
    /* prox=sign(x)*max{|x_i|-\lambda,0} */
    
    real_t g = 0.*lamda; 
    
    lamda    = data->mu * gamma;
    
    
    unsigned int i;
    for (i = 0; i < data->dimension; i++){
        input[i] = sign_x(input)*MAX(0.0, ABS(input[i]) - lamda);
        data->sum += *(data->cache + input[i]); 
    }
    
    g = data->mu*data->sum; 
    
    return g;
}



