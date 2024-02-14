#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vals(n);

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        vals[i] = input;
    }
    
    sort(vals.begin(), vals.end());

    int left, right;

    if (n % 2 == 0)
    {
        left = vals.size() / 2 - 1;
        right = vals.size() / 2;
        while (left >= 0 && right < n)
        {
            cout << vals[left] << " " << vals[right] << " ";
            left--;
            right++;
        }
        cout << endl;
    }
    else
    {
        left = vals.size() / 2;
        right = vals.size() / 2 + 1;
        while (left >= 1 && right < n)
        {
            cout << vals[left] << " " << vals[right] << " ";
            left--;
            right++;
        }
        cout << vals[0] << endl;
    }

    return 0;
}