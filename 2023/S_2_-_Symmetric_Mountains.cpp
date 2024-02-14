#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> mountains;
map<pair<int, int>, int> vals;

int value(int length)
{
    int lowest = 0;
    for (int i = 0; i < n - length + 1; i++)
    {
        int result = 0;
        if (vals.find({i, i + length - 1}) != vals.end()) 
        {
            result = vals[{i, i + length - 1}];
            if (i == 0 || result < lowest) lowest = result;
            continue;
        }

        int left = i + length / 2 - 1;
        int right = (length % 2 == 0) ? i + length / 2 : i + length / 2 + 1;
        while (left >= 0 && right < i + length)
        {
            if (vals.find({left, right}) != vals.end())
            {
                if (vals.find({left - 1, right + 1}) == vals.end())
                    result = vals[{left, right}];
            }
            else
            {
                result += abs(mountains[left] - mountains[right]);
                vals.insert({{left, right}, result});
            }
    
            left--;
            right++;
        }

        if (i == 0 || result < lowest) lowest = result;
    }

    return lowest;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        mountains.push_back(height);
    }

    for (int i = 1; i <= n; i++)
        cout << value(i) << " ";
    cout << endl;

    return 0;
}