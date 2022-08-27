#ifndef SQUARE_SOLVER_HPP_INCLUDED
#define SQUARE_SOLVER_HPP_INCLUDED

#include "utils.h"

//---------------------------------------------
/// @param [in] b coefficient equation
/// @param [in] c coefficient equation
/// @param [in] equation gets the structure
/// @note solves the linear case of the quadratic equation
//---------------------------------------------
void solve_linear_equation(double b, double c, equation *t);

//---------------------------------------------
/// @param [in] a coefficient equation
/// @param [in] b coefficient equation
/// @param [in] c coefficient equation
/// @param [in] equation gets the structure
/// @note solves the classical quadratic equation
//---------------------------------------------
void solve_square_equation(double a,  double b, double c, equation *t);

//---------------------------------------------
/// @param [in] a coefficient equation
/// @param [in] b coefficient equation
/// @param [in] c coefficient equation
/// @param [in] equation gets the structure
/// @note solves the quadratic equation(considering all cases)
//---------------------------------------------
void solve(double a,  double b, double c, equation *t);

//---------------------------------------------
/// @param [in] x coefficient equation
/// @param [in] y coefficient equation
/// @return 1 if the comparison is true
/// @note compares two numbers for equality
//---------------------------------------------
int is_equal(double x, double y);

#endif
