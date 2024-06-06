#include <iostream> 

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

void loop (int x_val)
{
    int mul_result = 1;
    for (int i=1; i<=x_val; i++)
    {
        mul_result = mul_result * i;
    }

    std::cout << "Using a loop: " << mul_result << "\n";
}

int main ()
{   
    int user_ip;
    std::cout << "Enter a number to see its factorial (!): \n";
    std::cin >> user_ip;
    while (user_ip < 0)
    {
        std::cout << "The basic factorial function is defined for numbers (0>)inclusive: \n";
        std::cin >> user_ip;
    }
    std::cout << "Factorial of " << user_ip << " is: " << factorial (user_ip) << "\n";
    loop (user_ip);

    return 0;
}
