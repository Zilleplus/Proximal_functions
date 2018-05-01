#include "../globals/globals.h"
#include "../include/indicator_box_function.h"

static struct indicator_box_square_function* data; 

int check_g(real_t* x,real_t g_x_solution){
    real_t g_x=data->g(x);
    if(g_x_solution!=g_x)return FAILURE;
    else return SUCCESS;
}

int main(){
    real_t upper_bound=2;
    real_t lower_bound=-2;
    constraint_functions_init_box(&data,2,lower_bound,upper_bound);

    data->dimension=2;
    
    /* test function g(x) */
    real_t x[2]={0,0};
    check_g(x,0.);

    x[0]=2;x[1]=0;
    check_g(x,LARGE);

    x[0]=0;x[1]=2;
    check_g(x,LARGE);

    x[0]=-2;x[1]=0;
    check_g(x,LARGE);

    x[0]=0;x[1]=-2;
    check_g(x,LARGE);

    /* test function proxg(x) */

    return SUCCESS;
}