#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    int result = 0;
    
    int a = n / 4;
    bool repeat = true;
    while (repeat)
    {
        repeat = false;

        for (int i = a; i >= 0; i--)
        {
            int j = a - i;
            int sum = 4 * i + 5 * j;
            if (sum == n) result++;

            if (sum > n)
            {
                repeat = true;
                a--;
                break;
            }
        }
    }

    cout << result << endl;
	
	return 0;
}