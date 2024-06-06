#include <iostream> 

/*
Recursion using regular Taylor series.
*/

float taylor_s (int x_val, int terms)
{
    static int pow_of_f = 1;
    static int d_fact = 1;
    float term_result;

    if (terms == 0)
    {
        pow_of_f = 1;
        d_fact = 1;
        return 1;
    }
    else
    {
        term_result = taylor_s (x_val, terms - 1);
        pow_of_f = pow_of_f * x_val;
        d_fact = d_fact * terms;
        return term_result + (pow_of_f / d_fact);
    }
}

/*
Recursion using Horners method.
*/

int t_horner (int x_val, int terms)
{
    static int result = 1;

    if (terms == 0)
    {
        return result;
    }
    else
    {
        result = 1 + (x_val / terms) * result;
        return t_horner (x_val, terms - 1);
    }
}

int main ()
{
    int f_val, num_terms;
    std::cout << "Enter the value of the function and also the number of terms you want: \n";
    std::cin >> f_val >> num_terms;
    while (num_terms < 0)
    {
        std::cout << "Please enter positive number of terms (0>)inclusive: \n";
        std::cin >> num_terms;
    }
    std::cout << "e raised to power of x where x is " << f_val << " for " << num_terms << " is: " << taylor_s (f_val, num_terms) << "\n";
    std::cout << "Using Horner's method: " << t_horner (f_val, num_terms) << "\n";
    return 0;
}