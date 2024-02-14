#include <iostream>

int main()
{
    int total = 0;
    for (int i = 1; i <= 50; i++)
    {
        total += i;
    }
    
    std::cout << total << std::endl;
    return 0;
}