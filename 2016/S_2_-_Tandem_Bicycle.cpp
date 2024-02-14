#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int q, n;
vector<int> sp1, sp2;
int totSp = 0;

void q1()
{
    for (int i = 0; i < n; i++)
    {
        totSp += max(sp1[i], sp2[i]);
    }

    cout << totSp << endl;
}

void q2()
{
    int l = 0, r = n - 1;

    while (l < n && r >= 0)
    {
        totSp += max(sp1[l], sp2[r]);

        l++;
        r--;
    }

    cout << totSp << endl;
}

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    cin >> q >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        sp1.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        sp2.push_back(input);
    }

    sort(sp1.begin(), sp1.end());
    sort(sp2.begin(), sp2.end());

    if (q == 1)
    {
        q1();
        return 0;
    }
    q2();
	return 0;
}