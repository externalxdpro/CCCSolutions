#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<bool>> vis;
vector<vector<int>> steps;
vector<pair<int, int>> cams;
vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> grid;

bool isValid(pair<int, int> pos)
{
    if (pos.first == 0 || pos.first == n - 1 || pos.second == 0 || pos.second == m - 1) return false;
    if (grid[pos.first][pos.second] == 'W') return false;
    if (vis[pos.first][pos.second]) return false;
    for (auto invalid : cams)
    {
        if (pos.first == invalid.first || pos.second == invalid.second) return false;
    }

    return true;
}

void search(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        for (pair<int, int> dir : directions)
        {
            int new_row = curr.first + dir.first;
            int new_col = curr.second + dir.second;
            if (isValid({new_row, new_col}))
            {
                q.push({new_row, new_col});
                vis[new_row][new_col] = true;
                steps[new_row][new_col] = steps[curr.first][curr.second] + 1;
            }
        }
    }
}

int main()
{
    pair <int, int> start;

    std::cin >> n >> m;

    vis = vector<vector<bool>>(n, vector<bool>(m));
    steps = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string input;
        std::cin >> input;
        grid.push_back(input);
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] == 'S') start = {i, j};
            if (input[j] == 'C') cams.push_back({i, j});
        }
    }

    search(start);

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (grid[i][j] != '.') continue;
            if (steps[i][j] == 0)
            {
                cout << -1 << endl;
                continue;
            }

            cout << steps[i][j] << endl;
        }
    }

    return 0;
}