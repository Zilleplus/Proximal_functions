#include "../globals/globals.h"
#include "../include/indicator_L0ball.h"
#include "stdio.h"
#include "stdlib.h"

static struct indicator_L0ball* data;


static int check_g_value_at_prox_of_x(real_t* x,const real_t g_x_solution){
    real_t initial_value_x[3];initial_value_x[0]=x[0];initial_value_x[1]=x[1];initial_value_x[2]=x[2]; /* save the inital value, used with printf */
    real_t gamma=0;
    real_t g_x=prox_indicator_L0ball(data,x,gamma);

    if(g_x_solution!=g_x){
        printf("Error Testing g(x), g([%f;%f;%f])=%f -> theoretical g(x)=%f \n",initial_value_x[0],initial_value_x[1],initial_value_x[2],g_x,g_x_solution);
        return FAILURE;
        
    }
    else return SUCCESS;
    
    
}

static int check_proxg_point(real_t* x,const real_t* proxg_x_solution){
    unsigned int i;
    real_t initial_value_x[2];initial_value_x[0]=x[0];initial_value_x[1]=x[1]; /* save the inital value, used with printf */
    real_t gamma=0;
    prox_indicator_L0ball(data,x,gamma);
    unsigned char solution_is_ok=TRUE;
    for (i = 0; i < data->dimension; i++){
        if(ABS(x[i]-proxg_x_solution[i])>(1e0)*MACHINE_ACCURACY){
            solution_is_ok=FALSE;
        }
    }
    if(solution_is_ok==FALSE) {
        printf("Error Testing proxg(x), proxg([%f,%f,%f])=[%f;%f;%f] instead of solution=[%f,%f,%f] \n",\
            initial_value_x[0],initial_value_x[1],initial_value_x[2],x[0],x[1],x[2],proxg_x_solution[0],proxg_x_solution[1],proxg_x_solution[2]);
        return FAILURE;
    }
    return SUCCESS;
}

int main(){
    unsigned int number_of_non_zero_elements = 2; 
    unsigned int dimension = 3;
    data =  init_L0ball(dimension,number_of_non_zero_elements);

    data->dimension=3;
    
    /* test function g(prox(x)) */
    printf("Testing indicator binary: g(x):Great! All tests passed \n");
    real_t x[3]={0,0,0};
    if(check_g_value_at_prox_of_x(x,0.)==FAILURE) return FAILURE;

    x[0]=-1.;x[1]=0;x[2]=0;
    if(check_g_value_at_prox_of_x(x,0.)==FAILURE) return FAILURE;

    /* test function proxg(x) point */
    printf("Testing indicator binary: proxg(x):Great! All tests passed  \n");
    real_t x_solution[3]={0,0,0};

    x[0]=1;x[1]=-2;x[2]=3;
    x_solution[0]=0;x_solution[1]=-2;x_solution[2]=3;
    if(check_proxg_point(x,x_solution)==FAILURE) return FAILURE;

    free(data);

    return SUCCESS;
}