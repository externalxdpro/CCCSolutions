#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c;
    cin >> c;
    vector<int> row1;
    vector<int> row2;

    for (int i = 0; i < c; i++)
    {
        int input;
        cin >> input;
        row1.push_back(input);
    }
    for (int i = 0; i < c; i++)
    {
        int input;
        cin >> input;
        row2.push_back(input);
    }

    int result = 0;

    for (int i = 0; i < c; i++)
    {
        if (row1[i] == 0) continue;

        result += 3;

        if (i != 0 && row1[i - 1] == 1) result--;
        if (i != c - 1 && row1[i + 1] == 1) result--;
        if (i % 2 == 0 && row2[i] == 1) result--;
    }
    for (int i = 0; i < c; i++)
    {
        if (row2[i] == 0) continue;

        result += 3;

        if (i != 0 && row2[i - 1] == 1) result--;
        if (i != c - 1 && row2[i + 1] == 1) result--;
        if (i % 2 == 0 && row1[i] == 1) result--;
    }

    cout << result << endl;
}