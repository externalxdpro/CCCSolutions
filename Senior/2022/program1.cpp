#include <iostream>

int goodFoursAndFives(int n)
{
    int result = 0;

    for (int i = 0; i <= n; i += 4)
    {
        for (int j = 0; j <= n; j += 5)
        {
            if (i + j == n)
            {
                result++;
            }
        }
    }

    return result;
}

int main()
{
    // int n = 14;
    // int n = 40;
    int n = 6;

    std::cout << goodFoursAndFives(n);

    return 0;
}