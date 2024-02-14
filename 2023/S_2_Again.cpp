#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> mtns;
map<pair<int, int>, int> vals;
int lows[10000] = {};

void count()
{
    cout << 0 << " ";
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int res;
            if (len == 2 || len == 3)
            {
                res = abs(mtns[i] - mtns[i + len - 1]);
                vals.insert({{i, i + len - 1}, res});
            }
            else
            {
                res = abs(mtns[i] - mtns[i + len - 1]) + vals[{i + 1, i + len - 2}];
                vals.insert({{i, i + len - 1}, res});
            }
            if (i == 0 || res < lows[len]) lows[len] = res;
        }

        cout << lows[len] << " ";
    }
    cout << endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        mtns.push_back(h);
    }

    count();

    return 0;
}