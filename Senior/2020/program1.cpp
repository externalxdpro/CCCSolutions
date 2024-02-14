#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, x;
    vector<vector<int>> m;
    double maxSpeed = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        cin >> x;

        vector<int> temp = {t, x};
        m.push_back(temp);
    }
    
    sort(m.begin(), m.end());

    for (vector<vector<int>>::iterator i = m.begin() + 1; i < m.end(); i++)
    {
        double time = i[0][0];
        double pos = i[0][1];
        vector<vector<int>>::iterator prev = i-1;
        double prevTime = prev[0][0];
        double prevPos = prev[0][1];

        double speed = abs(pos - prevPos) / (time - prevTime);
        if (maxSpeed < speed) maxSpeed = speed;
    }

    cout << maxSpeed << endl;

    return 0;
}