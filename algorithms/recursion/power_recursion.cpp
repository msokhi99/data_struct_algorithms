#include <iostream> 

int power (int x_val, int p_raise)
{
    if (p_raise == 0)
    {
        return 1;
    }
    else
    {
        return power (x_val, p_raise - 1) * x_val;
    }
}

void loop (int x_val, int pow)
{
    int sum = 1;

    for (int i=0; i<pow; i++)
    {
        sum = sum * x_val;
    }

    std::cout << "Using a loop: " << sum << "\n";
}

int main ()
{   
    int user_ip_val, pow_to_r; 
    std::cout << "Enter the number and the power you want to raise it to: \n";
    std::cin >> user_ip_val >> pow_to_r;
    while (pow_to_r < 0)
    {
        std::cout << "Please enter a positive number (0>)inclusive: \n";
        std::cin >> pow_to_r;
    }
    std::cout << user_ip_val << " raised to the power of " << pow_to_r << " is: " << power (user_ip_val, pow_to_r) << "\n";
    loop (user_ip_val, pow_to_r);
    return 0;
}