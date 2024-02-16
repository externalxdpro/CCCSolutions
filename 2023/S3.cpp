#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printGrid(vector<vector<char>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

void printGridRotated(vector<vector<char>> &grid) {
    for (int i = grid[0].size() - 1; i >= 0; i--) {
        for (int j = 0; j < grid.size(); j++) {
            cout << grid[j][i];
        }
        cout << '\n';
    }
}

void regCase(int n, int m, int r, int c) {
    vector<vector<char>> grid(n, vector(m, 'a'));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 'b';
        }
    }

    for (int i = r; i < n; i++) {
        for (int j = 0; j < c; j++) {
            grid[i][j] = 'b';
        }
    }

    printGrid(grid);
}

void randCase(int n, int m, int r, int c) {
    vector<vector<char>> grid(n, vector(m, 'a'));

    int letter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = letter + 'a';
            letter++;
            letter %= 26;
        }
        letter += (i + 1) * 3;
        letter %= 26;
    }

    printGrid(grid);
}

void case1(int n, int m, int r, int c, bool isM = false) {
    vector<vector<char>> grid(n, vector(m, 'a'));
    for (int i = 0; i < grid.size(); i++) {
        grid[i].back() = 'b';
    }

    for (int i = grid[0].size() - 1; i >= c; i--) {
        grid.back()[i]++;
    }

    if (isM) {
        printGridRotated(grid);
    } else {
        printGrid(grid);
    }
}

void case2(int n, int m, int r, int c, bool isM = false) {
    vector<vector<char>> grid(n, vector(m, 'a'));

    if (m % 2 == c % 2) {
        int palCols = m;
        int i       = 0;
        while (palCols > c) {
            grid[0][i]         = 'b';
            grid[0][m - i - 1] = 'b';
            i++;
            palCols -= 2;
        }
    } else if (m % 2 == 1) {
        int palCols = m;
        int i       = 0;
        while (palCols > c + 1) {
            grid[0][i]         = 'b';
            grid[0][m - i - 1] = 'b';
            i++;
            palCols -= 2;
        }

        grid[0][m / 2] = 'b';
    } else {
        cout << "IMPOSSIBLE\n";
        return;
    }

    if (isM) {
        printGridRotated(grid);
    } else {
        printGrid(grid);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    if (r == n && c == m || (r != n && r != 0 && c != m && c != 0)) {
        regCase(n, m, r, c);
    } else if (r == 0 && c == 0) {
        randCase(n, m, r, c);
    } else if (r == 0) {
        case1(n, m, r, c);
    } else if (r == n) {
        case2(n, m, r, c);
    } else if (c == 0) {
        case1(m, n, c, r, true);
    } else if (c == m) {
        case2(m, n, c, r, true);
    }

    return 0;
}
