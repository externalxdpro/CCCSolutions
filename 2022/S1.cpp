#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i <= n / 4; i++) {
        int newN = i * 4;
        if (newN == n) {
            ans++;
            break;
        }

        if (newN > n) {
            break;
        }

        if ((n - newN) % 5 == 0) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
