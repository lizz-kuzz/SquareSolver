#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>


enum solutions 
{
    EMPTINESS = 0,      ///<there are no roots
    ONE_SOLUTION = 1,   ///<one solution
    TWO_SOLUTIONS = 2,  ///<two solutions
    INF = 3             ///<infinity
};


//---------------------------------------------
/// @param [in] number_of_roots number of expected roots
/// @param [in] x_1 expected root
/// @param [in] x_2 expected root
//---------------------------------------------
typedef struct {
    enum solutions number_of_roots;
    double x_1;
    double x_2;
} equation;

#endif 