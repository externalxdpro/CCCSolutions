#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio();
    cin.tie();

    int troutPoints, pikePoints, pickerelPoints, totalPoints;
    cin >> troutPoints >> pikePoints >> pickerelPoints >> totalPoints;

    int combs = 0;
    for (int numTrout = 0; numTrout * troutPoints <= totalPoints; numTrout++) {
        for (int numPike = 0;
             numTrout * troutPoints + numPike * pikePoints <= totalPoints;
             numPike++) {
            for (int numPickerel = 0;
                 numTrout * troutPoints + numPike * pikePoints +
                     numPickerel * pickerelPoints <=
                 totalPoints;
                 numPickerel++) {
                if (numTrout == numPike == numPickerel == 0)
                    continue;
                cout << numTrout << " Brown Trout. " << numPike
                     << " Northern Pike. " << numPickerel
                     << " Yellow Pickerel. " << endl;
                combs++;
            }
        }
    }

    cout << "Number of ways to catch fish: " << combs << endl;
    return 0;
}
