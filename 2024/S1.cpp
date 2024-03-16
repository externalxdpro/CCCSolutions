#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> hs;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        hs.push_back(h);
    }

    int result = 0;
    for (int i = 0; i < hs.size()/2; i++)
    {
        if (hs[i] == hs[i+hs.size()/2]){
            result+=2;
        }
    }

    cout << result << '\n';

    return 0;
}
