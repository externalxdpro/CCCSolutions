#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<vector<int>, vector<int>> allPoints;
    pair<int, int> totals = {0, 0};
    int greatest = 0;

    for (int i = 0; i < n; i++)
    {
        int points;
        cin >> points;
        allPoints.first.push_back(points);
    }
    for (int i = 0; i < n; i++)
    {
        int points;
        cin >> points;
        allPoints.second.push_back(points);
    }
    
    for (int i = 0; i < n; i++)
    {
        totals.first += allPoints.first[i];
        totals.second += allPoints.second[i];
        if (totals.first == totals.second) greatest = i + 1;
    }
    
    cout << greatest << endl;
    
    return 0;
}