#include <iostream> 

int ncr (int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return ncr (n-1, r-1) + ncr (n-1, r);
    }
}

/*
Using the factorial function along with the general formula:
*/

int factorial (int x_val)
{
    if (x_val == 0)
    {
        return 1;
    }
    else
    {
        return factorial (x_val - 1) * x_val;
    }
}

void reg_f (int nn, int rr)
{
    int result; 

    result = factorial (nn) / (factorial (rr) * (factorial (nn - rr)));
    std::cout << "Using a regular function: " << result;
}

int main ()
{   
    int user_n, user_r;
    std::cout << "Enter the value of n and r: \n";
    std::cin >> user_n >> user_r;
    std::cout << user_n << "C" << user_r << " is: " << ncr (user_n, user_r) << "\n";
    reg_f (user_n, user_r);
    return 0;
}