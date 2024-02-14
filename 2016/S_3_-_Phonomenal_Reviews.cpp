#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<int, set<int>> roads;
set<int> locs;
int n, m;
int farNode = 0, maxDist = 0;

bool cut(int prev, int curr, int dist)
{
    if (roads[curr].size() > 1 || *roads[curr].begin() != prev)
    {
        bool noPhos = true;
        for (auto &next : set<int>(roads[curr]))
        {
            if (next != prev && cut(curr, next, dist + 1)) noPhos = false;
        }

        if (noPhos)
        {
            if (locs.count(curr) == 0)
            {
                roads.erase(curr);
                roads[prev].erase(curr);
                return false;
            }
            else
            {
                if (dist > maxDist)
                {
                    farNode = curr;
                    maxDist = dist;
                }
                return true;
            }
        }
    }
    else
    {
        if (locs.count(curr) == 0)
        {
            roads.erase(curr);
            roads[prev].erase(curr);
            return false;
        }
        else
        {
            if (dist > maxDist)
            {
                farNode = curr;
                maxDist = dist;
            }
            return true;
        }
    }
    return true;
}

void findFar(int prev = -1, int curr = farNode, int dist = 0)
{
    for (auto &next : roads[curr])
    {
        if (next != prev) findFar(curr, next, dist + 1);
    }

    if (dist > maxDist) maxDist = dist;
}

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        locs.insert(input);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        roads[a].insert(b);
        roads[b].insert(a);
    }

    cut(-1, *locs.begin(), 0);
    findFar();

    int totalDist = 0;
    for (auto &i : roads)
    {
        totalDist += i.second.size();
    }

    totalDist -= maxDist;
    cout << totalDist << endl;

	return 0;
}