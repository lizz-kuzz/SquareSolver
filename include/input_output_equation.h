#ifndef INPUT_OUTPUT_EQUATION_H_INCLUDED
#define INPUT_OUTPUT_EQUATION_H_INCLUDED

#include "utils.h"

//---------------------------------------------
/// @param [in] a coefficient equation
/// @param [in] b coefficient equation
/// @param [in] c coefficient equation
/// @return returns 1 if the coefficients are correct and 0 if the user wants to change the values
/// @note checks the correctness of the entered coefficients
//---------------------------------------------
int is_continue_quadratic_equation_solver(double a, double b, double c);

//---------------------------------------------
/// @param [in] a adress coefficient equation
/// @param [in] b adress coefficient equation
/// @param [in] c adress coefficient equation
/// @note gets the coefficients of the equation
//---------------------------------------------
double input_coeff(double *a, double *b, double *c);

//---------------------------------------------
/// @param [in] equation gets the structure
/// @note outputs solutions of the equation s with the entered coefficients
//---------------------------------------------
void output_solutions(equation square);

#endif
