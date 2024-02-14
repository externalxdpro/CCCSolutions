#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int numT = 0;
    int numS = 0;

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        string line;
        getline(cin, line);

        for (char i : line) {
            if (i == 't' || i == 'T') {
                numT++;
            } else if (i == 's' || i == 'S') {
                numS++;
            }
        }
    }

    if (numT > numS) {
        cout << "English" << endl;
    } else {
        cout << "French" << endl;
    }

    return 0;
}
