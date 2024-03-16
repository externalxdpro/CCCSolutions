// #define FMT_HEADER_ONLY

#include <bits/stdc++.h>
// #include <fmt/ranges.h>

using namespace std;

pair<bool, vector<vector<int>>> dp(vector<int> a, vector<int> b, int d, int l,
                                   int r, vector<vector<int>> curr,
                                   set<vector<int>> &found) {
    if (d == 0) {
        for (int i = l; i <= r; i++) {
            a[i] = a[l];
        }
    } else if (d == 1) {
        for (int i = l; i <= r; i++) {
            a[i] = a[r];
        }
    }

    if (found.count(a)) {
        return {false, {}};
    }
    if (a == b) {
        // fmt::print("{} {}\n", a, curr);
        return {true, curr};
    }
    // memo[a] = {false, {}};
    found.insert(a);

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < a.size() - 1; i++) {
            for (int j = a.size() - 1; j > 0; j--) {
                curr.push_back({t, i, j});
                auto result = dp(a, b, t, i, j, curr, found);
                if (result.first) {
                    return result;
                }
                curr.pop_back();
            }
        }
    }

    return {false, {}};
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        a[i] = curr;
    }
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        b[i] = curr;
    }

    // map<vector<int>, pair<bool, vector<vector<int>>>> memo;
    set<vector<int>> found;
    auto             result = dp(a, b, -1, -1, -1, {}, found);
    cout << (result.first ? "YES" : "NO") << '\n';
    if (!result.first) {
        return 0;
    }

    int size = result.second.size();
    cout << size << '\n';
    if (size == 0) {
        return 0;
    }

    for (auto i : result.second) {
        char d;
        if (i[0] == 0) {
            d = 'R';
        } else {
            d = 'L';
        }
        cout << d << ' ' << i[1] << ' ' << i[2] << '\n';
    }

    return 0;
}
