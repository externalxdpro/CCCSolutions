#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int x, y, g;
    vector<pair<string, string>> tog;
    vector<pair<string, string>> sep;

    cin >> x;
    for (int i = 0; i < x; i++)
    {
        string one, two;
        cin >> one >> two;
        tog.push_back({one, two});
    }
    
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        string one, two;
        cin >> one >> two;
        sep.push_back({one, two});
    }

    int violations = 0;
    cin >> g;
    for (int i = 0; i < g; i++)
    {
        string one, two, three;
        cin >> one >> two >> three;
        vector<string> grp = {one, two, three};

        for (pair<string, string> ppl : tog)
        {
            bool found1 = false;
            bool found2 = false;
            for (int index = 0; index < 3; index++)
            {
                if (!found1 && ppl.first == grp[index])
                {
                    found1 = true;
                    index = -1;
                    continue;
                }
                if (found1 && ppl.second == grp[index]) found2 = true;
            }
            if ((found1 && !found2) || (!found1 && found2))
            {
                violations++;
                continue;
            }
        }

        for (pair<string, string> ppl : sep)
        {
            bool found1 = false;
            bool found2 = false;
            for (int index = 0; index < 3; index++)
            {
                if (ppl.first == grp[index]) found1 = true;
                if (ppl.second == grp[index]) found2 = true;
            }
            if (found1 && found2)
            {
                violations++;
                continue;
            }
        }
    }

    cout << violations << endl;
	
	return 0;
}