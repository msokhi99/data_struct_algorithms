#include <iostream> 

int sum_nat_num (int x_val)
{
    if (x_val == 0)
    {
        return 0;
    }
    else 
    {
        return sum_nat_num (x_val - 1) + x_val;
    }
}

/*
Space complexity = O(n) as for n values the function makes (n+1) activation records. 
The degree of the polynomial is 1.
*/

/*
Every tail recursion can be converted into a loop.
*/

void loop (int x_val)
{
    int total_sum = 0;
    for (int i=1; i<=x_val; i++)
    {
        total_sum = total_sum + i;
    }

    std::cout << "Using a loop: " << total_sum << "\n";
}

/*
Time complexity = O(n).
*/

int main ()
{   
    int user_ip;
    std::cout << "Enter the number you would like to sum upto: \n";
    std::cin >> user_ip;
    while (user_ip < 1)
    {
        std::cout << "Natural numbers are (1>) inclusive. Please enter the number again: \n";
        std::cin >> user_ip;
    }
    std::cout << "The total sum of numbers upto " << user_ip << " is: " << sum_nat_num (user_ip) << "\n"; 

    loop (user_ip);
    return 0;
}