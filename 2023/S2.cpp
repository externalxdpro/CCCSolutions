#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> symmetric(vector<int> &mtns) {
    vector<int> result(mtns.size(), INT_MAX);
    result[0] = 0;

    for (int i = 1; i < mtns.size() - 1; i++) {
        int l = i - 1, r = i + 1;
        int diff = 0;
        while (l >= 0 && r < mtns.size()) {
            diff += abs(mtns[l] - mtns[r]);
            result[r - l] = min(result[r - l], diff);
            l--;
            r++;
        }
    }

    for (int i = 0; i < mtns.size() - 1; i++) {
        int l = i, r = i + 1;
        int diff = 0;
        while (l >= 0 && r < mtns.size()) {
            diff += abs(mtns[l] - mtns[r]);
            result[r - l] = min(result[r - l], diff);
            l--;
            r++;
        }
    }

    return result;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> mtns(n);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        mtns[i] = h;
    }

    vector<int> result = symmetric(mtns);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}
