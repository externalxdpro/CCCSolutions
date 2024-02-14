#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> villages;

    for (int i = 0; i < n; i++)
    {
        double input;
        cin >> input;
        villages.push_back(input);
    }
    sort(villages.begin(), villages.end());

    double smallest = villages[n - 1] - villages[0];

    for (int i = 1; i < villages.size() - 1; i++)
    {
        double left = (villages[i] - villages[i - 1]) / 2;
        double right = (villages[i + 1] - villages[i]) / 2;
        double result = left + right;
        if (result < smallest)
        {
            smallest = result;
        }
    }
    cout << fixed << setprecision(1) << smallest << endl;

    return 0;
}