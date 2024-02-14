#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int numQ, m1, m2, m3;
    cin >> numQ >> m1 >> m2 >> m3;

    int plays = 0;
    while (numQ > 0) {
        if (--numQ >= 0) {
            m1++;
            if (m1 % 35 == 0) {
                numQ += 30;
            }
            plays++;
        }
        if (--numQ >= 0) {
            m2++;
            if (m2 % 100 == 0) {
                numQ += 60;
            }
            plays++;
        }
        if (--numQ >= 0) {
            m3++;
            if (m3 % 10 == 0) {
                numQ += 9;
            }
            plays++;
        }
    }

    string plural = plays == 1 ? "time" : "times";
    cout << "Martha plays " << plays << ' ' << plural << " before going broke."
         << endl;

    return 0;
}
