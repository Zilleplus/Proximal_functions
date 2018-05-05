#include "../globals/globals.h"
#include "../include/indicator_box_function.h"
#include<stdlib.h>



struct indicator_box_square_function* constraint_functions_init_box(\
    const unsigned int dimension_,const real_t lower_bound,const real_t upper_bound,const real_t value_inf){

    struct indicator_box_square_function* data = malloc(sizeof(struct indicator_box_square_function));
    if(data==NULL) return NULL;

    data->dimension=dimension_;
    data->lower_bound=lower_bound;
    data->upper_bound=upper_bound;
    data->inf=value_inf;

    return data;
}

real_t proxg_indicator_box_square_function(const struct indicator_box_square_function* data,real_t* input){
    unsigned int i;
    real_t g=0;
    for (i = 0; i < data->dimension; i++)
    {
        if(input[i]<data->lower_bound)
        {
            input[i]=data->lower_bound;
            g=data->inf;
        }
        else if (input[i]>data->upper_bound)
        {
            input[i]=data->upper_bound;
            g=data->inf;
        }
    }

    return g;
}