#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool searched[1000][1000];
vector<vector<pair<int, int>>> vals = vector<vector<pair<int, int>>>(1000000);

string isPossible(pair<int, int> lastCell)
{
    queue<pair<int, int>> q;
    q.push(lastCell);

    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();
        vector<pair<int, int>> neighbours = vals[cell.first * cell.second];
        for (pair<int, int> neighbour : neighbours)
        {
            if (neighbour.first == 1 && neighbour.second == 1) return "yes";
            else if (!searched[neighbour.first][neighbour.second])
            {
                searched[neighbour.first][neighbour.second] = true;
                q.push(neighbour);
            }
        }
    }

    return "no";
}

int main()
{
    int m, n;
    cin >> m >> n;
    pair<int, int> lastCell;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int val;
            cin >> val;
            pair<int, int> cell = make_pair(i, j);
            vals[val].push_back(cell);

            if (i == m && j == n)
            {
                lastCell = cell;
            }
        }
    }

    cout << isPossible(lastCell) << endl;

    return 0;
}