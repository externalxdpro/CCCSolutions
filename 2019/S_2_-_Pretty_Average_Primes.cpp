#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num)
{
    bool result = true;
    for (int i = 2; i * i < num; i++)
    {
        if (num % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];

        for (int a = 2; a < n[i]; a++)
        {
            int b = 2 * n[i] - a;
            if (isPrime(a) && isPrime(b) && a + b == 2 * n[i])
            {
                cout << a << " " << b << endl;
                break;
            }
        }
    }


    return 0;
}