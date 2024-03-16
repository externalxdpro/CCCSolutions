#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t >> n;

    vector<string> strings;
    for (int i = 0; i < t; i++) {
        string curr;
        cin >> curr;
        strings.push_back(curr);
    }

    for (string s : strings) {
        map<char, int> occurences;
        for (int i = 0; i < s.size(); i++) {
            occurences[s[i]]++;
        }

        bool heavyFirst = occurences[s[0]] > 1;
        bool done       = false;
        for (int i = 1; i < s.size(); i++) {
            if (heavyFirst) {
                if (i % 2) {
                    if (occurences[s[i]] > 1) {
                        cout << "F\n";
                        done = true;
                        break;
                    }
                } else {
                    if (occurences[s[i]] == 1) {
                        cout << "F\n";
                        done = true;
                        break;
                    }
                }
            } else {
                if (i % 2) {
                    if (occurences[s[i]] == 1) {
                        cout << "F\n";
                        done = true;
                        break;
                    }
                } else {
                    if (occurences[s[i]] > 1) {
                        cout << "F\n";
                        done = true;
                        break;
                    }
                }
            }
        }

        if (!done) {
            cout << "T\n";
        }
    }

    return 0;
}
