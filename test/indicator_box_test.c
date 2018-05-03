#include "../globals/globals.h"
#include "../include/indicator_box_function.h"

static struct indicator_box_square_function* data; 

static int check_g(const real_t* x,const real_t g_x_solution){
    real_t g_x=data->g(x);
    if(g_x_solution!=g_x)return FAILURE;
    else return SUCCESS;
}

static int check_proxg(const real_t* x,const real_t* proxg_x_solution){
    unsigned int i;
    for (i = 0; i < data->dimension; i++)
    {
        if(ABS(x[i]-proxg_x_solution[i])>MACHINE_ACCURACY){
            printf("Error on index %d x=%f instead of solution=%f",i,x[i],proxg_x_solution[i]);
            return FAILURE;
        }
            
    }
    return SUCCESS;
}

int main(){
    real_t upper_bound=1;
    real_t lower_bound=-1;
    constraint_functions_init_box(&data,2,lower_bound,upper_bound);

    data->dimension=2;
    
    /* test function g(x) */
    real_t x[2]={0,0};
    if(check_g(x,0.)==FAILURE) return FAILURE;

    x[0]=2;x[1]=0;
    if(check_g(x,LARGE)==FAILURE) return FAILURE;

    x[0]=0;x[1]=2;
    if(check_g(x,LARGE)==FAILURE) return FAILURE;

    x[0]=-2;x[1]=0;
    if(check_g(x,LARGE)==FAILURE) return FAILURE;

    x[0]=0;x[1]=-2;
    if(check_g(x,LARGE)==FAILURE) return FAILURE;

    /* test function proxg(x) */
    real_t x_solution[2]={0,0};

    x[0]=2;x[1]=0;
    x_solution[0]=0;x_solution[1]=0;
    if(check_proxg(x,x_solution)==FAILURE) return FAILURE;

    return SUCCESS;
}