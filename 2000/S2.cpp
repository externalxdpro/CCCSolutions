#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> streams;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int flow;
        cin >> flow;
        streams.push_back(flow);
    }

    while (true) {
        int input = 0;
        cin >> input;

        if (input == 77) {
            break;
        }

        if (input == 99) {
            int i, percent;
            cin >> i >> percent;
            i--;

            int amount = streams[i] * percent / 100;
            streams.insert(streams.begin() + i, amount);
            streams[i + 1] -= amount;
        }

        if (input == 88) {
            int i;
            cin >> i;
            i--;

            streams[i] += streams[i + 1];
            streams.erase(streams.begin() + i + 1);
        }
    }

    for (int i : streams) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
