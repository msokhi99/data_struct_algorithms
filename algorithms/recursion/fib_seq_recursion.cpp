#include <iostream> 

int arr[15];

int fib_seq (int f_element)
{
    if (f_element == 0)
    {
        return 0;
    }
    else if (f_element == 1)
    {
        return 1;
    }
    else
    {
        return fib_seq (f_element - 2) + fib_seq (f_element - 1);
    }
}

/*
Fibonacci series using memoization.
*/

int fib_memo (int x_val)
{
    if (x_val <= 1)
    {
        arr[x_val] = x_val;
        return x_val;
    }
    else if (arr[x_val - 2] == 0)
    {
        arr[x_val - 2] = fib_memo (x_val - 2);
    }
    else if (arr[x_val - 1] == 0)
    {
        arr[x_val - 1] = fib_memo (x_val - 1);
    }

    return fib_memo (x_val - 2) + fib_memo (x_val - 1);
}

int main ()
{   
    int user_ip;
    std::cout << "Enter the number of the element you want from the Fibonacci sequence: \n";
    std::cin >> user_ip;
    while (user_ip < 0)
    {
        std::cout << "Fibonacci sequence starts from 0. Please enter again: \n";
        std::cin >> user_ip;
    }
    std::cout << "The fibonacci element at index " << user_ip << " is: " << fib_seq (user_ip) << "\n";
    std::cout << "Using memoization technique: " << fib_memo (user_ip) << "\n";
    return 0;
}