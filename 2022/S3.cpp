#include <bits/stdc++.h>

using namespace std;

#define ll long long

void notes(ll n, ll m, ll k) {
    vector<int> seq(n, 0);
    seq[0] = 1;
    k -= n;

    for (int i = 0; i < m; i++) {
        if (k >= i && i < n) {
            seq[i] = i + 1;
            k -= i;
        } else {
            break;
        }
    }

    auto it   = find(seq.begin(), seq.end(), 0);
    int  curr = it - seq.begin();

    for (int i = curr; i < n; i++) {
        if (k > 0) {
            for (int j = m; j > 0; j--) {
                if (k - j + 1 >= 0) {
                    seq[i] = seq[i - j];
                    k -= j - 1;
                    break;
                }
            }
        } else {
            seq[i] = seq[i - 1];
        }
    }

    if (k == 0) {
        for (int i : seq) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    notes(n, m, k);

    return 0;
}
