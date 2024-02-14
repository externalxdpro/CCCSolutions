#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<string> names;
    vector<int> rams;
    vector<int> cpus;
    vector<int> disks;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int r;
        int s;
        int d;

        cin >> name >> r >> s >> d;

        names.push_back(name);
        rams.push_back(r);
        cpus.push_back(s);
        disks.push_back(d);
    }

    pair<string, int> greatest = {"", 0};
    pair<string, int> secondGreatest = {"", 0};
    for (int i = 0; i < names.size(); i++) {
        string name = names[i];
        int r = rams[i];
        int s = cpus[i];
        int d = disks[i];

        int result = 2 * r + 3 * s + d;
        if (result > greatest.second ||
            (result == greatest.second && name < greatest.first)) {
            secondGreatest = greatest;
            greatest = {name, result};
        } else if (result > secondGreatest.second ||
                   (result == secondGreatest.second &&
                    name < secondGreatest.first)) {
            secondGreatest = {name, result};
        }
    }

    cout << greatest.first << endl;
    cout << secondGreatest.first << endl;
    return 0;
}
