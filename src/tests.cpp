#include <stdlib.h>
#include <assert.h>
#include "../include/square_solver.h"
#include "../include/utils.h"
#include "../include/tests.h"

const int LINE = 6;
const int COLUMN = 6; 

const char *INPUT_FILE_WITH_TESTS = "res/unit_test.txt";

void test_solve_square_add(equation square, int number_of_roots, double x_1, double x_2)
{
    printf("FAILED: number_of_roots = %d, x_1 = %lg, x_2 = %lg\n"
           "Expected: number_of_roots = %d, x_1 = %lg, x_2 = %lg\n\n",
           square.number_of_roots, square.x_1, square.x_2, number_of_roots, x_1, x_2);
}

int call_test(double a, double b, double c, int number_of_roots, double x_1, double x_2)
{
    equation square = {
        .number_of_roots = EMPTINESS, 
        .x_1 = 0, 
        .x_2 = 0       
    };

    solve_square_equation(a, b, c, &square);

    if (square.number_of_roots != number_of_roots || \
        !is_equal(square.x_1, x_1) || !is_equal(square.x_2, x_2))
    {
        test_solve_square_add(square, number_of_roots, x_1, x_2);

        return 0;
    }
    else
    {
       return 1;
    }
}

void test_solve_square()
{
    int ok_test = 0;

    ok_test += call_test(1, 0, -4, TWO_SOLUTIONS, -2, 2);
    ok_test += call_test(1, 1, -6, TWO_SOLUTIONS, -3, 2);
    ok_test += call_test(0, 0, -6, EMPTINESS, 0, 0);
    ok_test += call_test(0, 1, -6, ONE_SOLUTION, 6, 0);
    ok_test += call_test(0, 0, 0, INF, 0, 0);

    printf("passed %d/5 checks\n", ok_test);
}

void test_from_file()
{
    FILE *finput = nullptr;

    finput = fopen(INPUT_FILE_WITH_TESTS, "r");

    if (finput != nullptr)
    {
        printf("Succes\n");
    }    
    else 
    {
        printf("File not found\n");
        return;
    }
    double massiv_tests[LINE][COLUMN] = {}; 

    for (int i = 0; i < LINE; i++)
    {
        fscanf(finput, "%lg %lg %lg %lg %lg %lg  ",
        &massiv_tests[i][0], &massiv_tests[i][1], &massiv_tests[i][2],
        &massiv_tests[i][3], &massiv_tests[i][4], &massiv_tests[i][5]);
    }

    int ok_test = 0;

    for (int i = 0; i < LINE; i++)
    {
        ok_test += call_test(massiv_tests[i][0], massiv_tests[i][1], massiv_tests[i][2],
                             (int)massiv_tests[i][3], massiv_tests[i][4], massiv_tests[i][5]); 
    }

    printf("passed %d/6 checks\n", ok_test);

    fclose(finput);
}