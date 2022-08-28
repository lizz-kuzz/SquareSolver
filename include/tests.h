#ifndef TESTS_HPP_INCLUDED
#define TESTS_HPP_INCLUDED

#include "utils.h"

//---------------------------------------------
/// @note text the function of solving a quadratic equation
/// @note he function calls a check of the operation of the quadratic equation solution function
/// @note outputs the number of passed checks
//---------------------------------------------
void test_solve_square();

//---------------------------------------------
/// @param [in] a coefficient equation
/// @param [in] b coefficient equation
/// @param [in] c coefficient equation
/// @param [in] number_of_roots number of expected roots
/// @param [in] x_1 expected root
/// @param [in] x_2 expected root
/// @return 1 if the check is passed
/// @note calls the solve function to check its operation
//---------------------------------------------
int call_test(double a, double b, double c, int number_of_roots, double x_1, double x_2);

//---------------------------------------------
/// @note displays an error message in the verification
//---------------------------------------------
void test_solve_square_add(equation square, int number_of_roots, double x_1, double x_2);

//---------------------------------------------
/// @note reads coefficients and roots from the file and checks the function operation
//---------------------------------------------
void test_from_file();

#endif