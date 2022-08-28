#include "../include/input_output_equation.h"
#include "../include/square_solver.h"
#include "../include/utils.h"
#include "../include/tests.h"
//------------------------------------------------
//! @param [in]    a - coefficient
//! @param [in]    b - coefficient
//! @param [in]    c - coefficient
//! @param [out]  x_1 - one solution
//! @param [out]  x_2 - two solution


/// @date         23.08.2022
/// @authors      Kuznetsova Elizaveta(https://github.com/lizz-kuzz)
/// @param [in]    a - coefficient
/// @param [in]    b - coefficient
/// @param [in]    c - coefficient
/// @param [out]  x_1 - one solution
/// @param [out]  x_2 - two solution
//------------------------------------------------
// TODO: README.md написать 
// вопрос: как сделать ссылку на доксиген

int main()
{
    double a = NAN, b = NAN, c = NAN;

    equation square = {
        .number_of_roots = EMPTINESS,
        .x_1 = NAN,
        .x_2 = NAN
    };

    input_coeff(&a, &b, &c);

    solve_square_equation(a, b, c, &square);
    
    output_solutions(square);
    
    test_from_file();
    
    return 0;
}
