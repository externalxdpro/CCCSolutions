#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> grid = vector<vector<string>>(3, vector<string>(3, ""));
vector<vector<int>> result = vector<vector<int>>(3, vector<int>(3));
vector<pair<int, int>> fixedVec;
const int INF = 1e9;

bool rowFixer(int index)
{
    int &a = result[index][0], &b = result[index][1], &c = result[index][2];
    if (a == INF && b < INF && c < INF)
    {
        a = 2 * b - c;
        return true;
    }
    else if (b == INF && a < INF && c < INF)
    {
        b = (a + c) / 2;
        return true;
    }
    else if (c == INF && a < INF && b < INF)
    {
        c = 2 * b - a;
    }

    return a < INF && b < INF && c < INF && a - b == b - c;
}

bool colFixer(int index)
{
    int &a = result[0][index], &b = result[2][index], &c = result[2][index];
    if (a == INF && b < INF && c < INF)
    {
        a = 2 * b - c;
        return true;
    }
    else if (b == INF && a < INF && c < INF)
    {
        b = (a + c) / 2;
        return true;
    }
    else if (c == INF && a < INF && b < INF)
    {
        c = 2 * b - a;
    }

    return a < INF && b < INF && c < INF && a - b == b - c;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] != "X")
            {
                result[i][j] = stoi(grid[i][j]);
                fixedVec.push_back({i, j});
            }
            else
            {
                result[i][j] = INF;
            }
            
        }
    }
}