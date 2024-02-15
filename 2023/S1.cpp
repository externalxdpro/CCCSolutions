#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int length(vector<vector<int>> tiles) {
    int result = 0;
    for (int i = 0; i < tiles[0].size(); i++) {
        if (tiles[0][i]) {
            result += 3;
            if (i != 0 && tiles[0][i - 1]) {
                result -= 2;
            }
        }
    }

    for (int i = 0; i < tiles[1].size(); i++) {
        if (tiles[1][i]) {
            result += 3;
            if (i != 0 && tiles[1][i - 1]) {
                result -= 2;
            }
            if (i % 2 == 0 && tiles[0][i]) {
                result -= 2;
            }
        }
    }

    return result;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    vector<vector<int>> tiles(2, vector(c, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < c; j++) {
            int curr;
            cin >> curr;
            tiles[i][j] = curr;
        }
    }

    cout << length(tiles) << '\n';

    return 0;
}
