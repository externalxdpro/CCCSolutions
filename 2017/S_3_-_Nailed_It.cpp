#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxL = 0;
int numH = 1;
int lengthCount[2001] = {};
int fullLengths[4001] = {};

void count()
{
    for (int i = 0; i <= 2000; i++)
    {
        if (lengthCount[i] > 0)
        {
            if (lengthCount[i] > 1) fullLengths[i * 2] += lengthCount[i] / 2;

            for (int j = i + 1; j <= 2000; j++)
            {
                if (lengthCount[j] > 0) fullLengths[i + j] += min(lengthCount[i], lengthCount[j]);
            }
        }
    }
}

void search()
{
    for (int i = 0; i <= 4000; i++)
    {
        if (fullLengths[i] > maxL)
        {
            maxL = fullLengths[i];
            numH = 1;
        }
        else if (fullLengths[i] == maxL) numH++;
    }
}

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    int input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        lengthCount[input]++;
    }

    count();
    search();
	
    cout << maxL << " " << numH << endl;
	return 0;
}
