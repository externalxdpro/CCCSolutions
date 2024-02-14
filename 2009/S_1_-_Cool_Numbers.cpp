#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    double square_end = sqrt(b);
    double cube_end = cbrt(b);

    int numCool = 0;
    for (int i = sqrt(a); i <= square_end; i++) {
        for (int j = 0; j <= cube_end; j++) {
            if (i * i == j * j * j) {
                numCool++;
            }
        }
    }

    cout << numCool << endl;
    return 0;
}
