#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, r, c;
vector<string> grid;

void construct()
{
    for (int i = 0; i < n; i++)
    {
        string line = "";
        for (int j = 0; j < m; j++)
        {
            if (i < r) line += 'a';
            else if (j < c) line += 'a';
            else line += (char)(rand() % 25 + 98);
        }
        grid.push_back(line);
    }
    
    for (string line : grid)
        cout << line << endl;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c;

    if ((r == n && c != m) || (c == m && r != n))
        cout << "IMPOSSIBLE" << endl;
    else
    {
        srand(time(NULL));
        construct();
    }

    return 0;
}