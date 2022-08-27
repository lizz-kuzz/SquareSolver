#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include "../include/input_output_equation.h"
#include "../include/utils.h"

void input_coeff(double *a, double *b, double *c)
{
    assert(a != nullptr && "Ptrs must not be NULL");
    assert(b != nullptr && "Ptrs must not be NULL");
    assert(c != nullptr && "Ptrs must not be NULL");
    
    int number_for_continue = 1;

    while (number_for_continue)
    {
        printf("enter the coefficients of the quadratic equation (a, b and c respectively) \n");
      
        if (scanf("%lg %lg %lg", a, b, c) != 3)
        {
            printf("try again, you entered an incorrect value\n");
            clear_input_buff();
        }
        else 
        {
            number_for_continue = is_continue_quadratic_equation_solver(*a, *b, *c);
        }
    }
}

int is_continue_quadratic_equation_solver(double a, double b, double c)
{  
    assert(std::isfinite(a) && "enter new coefficients");
    assert(std::isfinite(b) && "enter new coefficients");
    assert(std::isfinite(c) && "enter new coefficients");

    int number_for_continue = 0; 
    int is_continue_input_coeff = 1; 

    while (is_continue_input_coeff)
    {
        printf("check if the values are correct: \n");
        printf("(%lg)*x^2 +(%lg)*x +(%lg) = 0\n", a, b, c);
        printf("if everything are correct enter 0, if you want to change coefficients, enter 1: \n");
        
        int err = scanf("%d", &number_for_continue); 

        if (err != 1 && number_for_continue != 1 && number_for_continue != 0)
        {
            clear_input_buff();
            printf("try again, you entered an incorrect value\n");
        }
        else
        {
            is_continue_input_coeff = 0;
        }
    }

    return number_for_continue;
}

void output_solutions(equation square)
{
    switch (square.number_of_roots)
    {
        case ONE_SOLUTION:
                printf("the equation has one solution: x = %lg\n", square.x_1);
                break;
        case EMPTINESS:
                printf("the solution of the equation is an empty set!\n");
                break;
        case INF:
                printf("the solution of the equation is a set of real numbers!\n");
                break;
        case TWO_SOLUTIONS:
                printf("the equation has two solutions: x_1 = %lg, x_2 = %lg\n", square.x_1, square.x_2);
                break;
        default:
                printf("Error default switch in fucntion output_solutions");
    }
}

void clear_input_buff()
{
    while (getchar() != '\n') {}
}
