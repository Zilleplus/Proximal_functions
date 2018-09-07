#include "../globals/globals.h"
#include "../include/L1_norm.h"
#include<stdlib.h>



struct L1_norm* init_L1_norm(const unsigned int dimension,const real_t mu){
    struct L1_norm* data = malloc(sizeof(struct L1_norm));
    if(data==NULL) goto fail_1;

    data->dimension=dimension;
    data->mu=mu;


    real_t *cache;
    double sum;
    
    data->cache = malloc(data->dimension*sizeof(int));
    if(data->cache==NULL) goto fail_2;
    data->sum  = 0;
    //free(cache);

    return data;

    fail_2:
        free(data);
    fail_1:
        return NULL;
}

static real_t sign_x(real_t x) { return x<0 ? -1 : x>0 ? 1 : x;}

real_t  prox_L1_norm(const struct one_norm* data, real_t* input, real_t gamma){
    /* prox=sign(x)*max{|x_i|-\lambda,0} */
    
    real_t g = 0.0; 
    
    lamda    = data->mu * gamma;
    
    
    unsigned int i;
    for (i = 0; i < data->dimension; i++){
        input[i] = sign_x(input[i])*MAX(0.0, ABS(input[i]) - lamda);
        data->sum += *(data->cache + input[i]); 
    }
    
    g = data->mu*data->sum; 
    
    return g;
}



