#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int togNum, sepNum, groupsNum;
    unordered_map<string, unordered_set<string>> tog, sep;
    int ans = 0;

    cin >> togNum;
    for (int i = 0; i < togNum; i++) {
        string one, two;
        cin >> one >> two;
        tog[one].insert(two);
        tog[two].insert(one);
    }

    cin >> sepNum;
    for (int i = 0; i < sepNum; i++) {
        string one, two;
        cin >> one >> two;
        sep[one].insert(two);
        sep[two].insert(one);
    }

    cin >> groupsNum;
    for (int i = 0; i < groupsNum; i++) {
        string one, two, three;
        cin >> one >> two >> three;

        if (sep[one].count(two)) {
            ans++;
        }
        if (sep[one].count(three)) {
            ans++;
        }
        if (sep[two].count(one)) {
            ans++;
        }
        if (sep[two].count(three)) {
            ans++;
        }
        if (sep[three].count(one)) {
            ans++;
        }
        if (sep[three].count(two)) {
            ans++;
        }

        for (string name : tog[one]) {
            if (name != two && name != three) {
                ans++;
            }
        }
        for (string name : tog[two]) {
            if (name != one && name != three) {
                ans++;
            }
        }
        for (string name : tog[three]) {
            if (name != one && name != two) {
                ans++;
            }
        }
    }

    cout << ans / 2 << endl;
    return 0;
}
