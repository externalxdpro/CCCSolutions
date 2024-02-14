#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int w, n;
    cin >> w >> n;
    int cars[n];

    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        cars[i] = weight;
    }
    
    bool broken = false;
    for (int i = 0; i < n; i++)
    {
        int j = i + 3;
        if (j >= n) j = n - 1;

        int total = 0;
        for (int car = i; car <= j; car++)
        {
            total += cars[car];
        }

        if (total > w) 
        {
            broken = true;
            cout << i << endl;
            break;
        }
    }

    if (!broken) cout << n << endl;
	
	return 0;
}