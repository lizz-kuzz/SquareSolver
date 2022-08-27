#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include "../include/square_solver.h"
#include "../include/utils.h"

const double EPS = 1e-8;

void solve_linear_equation(double b, double c, equation *t)
{
    assert(t != nullptr && "Ptrs must not be NULL");
    
    if (is_equal(b, 0))
    {
        if (is_equal(c, 0))
            t->number_of_roots = INF;
        else
            t->number_of_roots = EMPTINESS;
    }
    else 
    {
        t->x_1 = -c / b;
        t->number_of_roots = ONE_SOLUTION;
    }
}

void solve_square_equation(double a,  double b, double c, equation *t)
{
    assert(t != nullptr && "Ptrs must not be NULL");

    double D = 0;

    if (is_equal(a, 0)) 
    {
        solve_linear_equation(b, c, t);
    }
    else
    {   
        double double_a = 2*a;
        D = b*b - 4*a*c;

        if (is_equal(D, 0))
        {
            t->x_1 = -b / double_a;
            t->number_of_roots = ONE_SOLUTION;
        }
        else if (D < 0)
        {
            t->number_of_roots = EMPTINESS;
        }
        else 
        {
            D = sqrt(D);
            t->x_1 = (-b - D) / double_a;
            t->x_2 = (-b + D) / double_a;
            t->number_of_roots = TWO_SOLUTIONS;
        }
    }
}

int is_equal(double x, double y)
{
    assert(std::isfinite(x) && "error");
    assert(std::isfinite(y) && "error");
    assert(x != NAN);
    assert(y != NAN);

    return fabs(x-y) < EPS;
}
