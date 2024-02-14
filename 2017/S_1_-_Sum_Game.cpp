#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> scores(2, vector<int>(n));

    int input;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            scores[i][j] = input;
        }
    }

    if (n == 1)
    {
        if (scores[0][0] == scores[1][0]) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    int sum1, sum2;
    sum1 = scores[0][0];
    sum2 = scores[1][0];

    int greatest = 0;

    for (int i = 1; i < n; i++)
    {
        sum1 += scores[0][i];
        sum2 += scores[1][i];

        if (sum1 == sum2)
        {
            greatest = i + 1;
        }
    }

    cout << greatest << endl;
    return 0;
}