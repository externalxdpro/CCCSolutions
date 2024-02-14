#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> readings(2e6 + 100, 0);
    int n;
    cin >> n;
    int g = 0;

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        if (r > g) g = r;
        readings[r]++;
    }

    int greatest = 0;
    int secGreatest = 0;
    bool moreThanOne = false;
    for (int i = 1; i <= g; i++)
    {
        if (readings[i] > readings[greatest])
        {
            greatest = i;
            moreThanOne = false;
        }
        else if (readings[i] == readings[greatest]) 
        {
            greatest = i;
            moreThanOne = true;
        }
    }

    for (int i = 1; i <= g; i++)
        if (readings[i] >= readings[secGreatest] && readings[i] < readings[greatest]) secGreatest = i;

    int result = 0;

    if (moreThanOne)
    {
        for (int i = 0; i <= g; i++)
        {
            if (readings[i] == readings[greatest])
            {
                result = greatest - i;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i <= g; i++)
        {
            if (readings[i] == readings[secGreatest])
            {
                int curr = abs(greatest - i);
                if (curr > result) result = curr;
            }
        }
    }

    cout << result << endl;
    return 0;
}