#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    vector<string> first(n);
    vector<string> second(n);

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        first[i] = input;
    }
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        second[i] = input;
    }
 
    map<string, string> assignments;
    for (int i = 0; i < n; i++)
        assignments.insert({first[i], second[i]});
    
    bool bad = false;
    for (int i = 0; i < n; i++)
    {
        if (first[i] == second[i] || assignments[first[i]] != second[i] || assignments[second[i]] != first[i])
        {
            bad = true;
            break;
        }
    }
    
    if (bad) cout << "bad" << endl;
    else cout << "good" << endl;

	return 0;
}