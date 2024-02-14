#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define pairlonglong pair<long long, pair<bool, long long>>

vector<pairlonglong> arr;

bool compare(pairlonglong a, pairlonglong b)
{
    if (a.first < b.first) return true;
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    long long p, w, d;
    long long left = 0, right = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> p >> w >> d;
        arr.push_back({max(0LL, p - d), {false, w}});
        arr.push_back({p + d, {true, w}});
        ans += max(0LL, p - d) * w;
        right += w;
    }
    sort(arr.begin(), arr.end(), compare);

    arr.insert(arr.begin(), {0LL, {false, 0LL}});

    long long temp = ans;

    for (int i = 1; i < arr.size(); i++)
    {
        while (i < arr.size() && arr[i - 1].first == arr[i].first)
        {
            if (arr[i].second.first == true)
            {
                left += arr[i].second.second;
            }
            else
            {
                right -= arr[i].second.second;
            }
            i++;
        }
        temp += (left - right) * (arr[i].first - arr[i - 1].first);
        ans = min(ans, temp);
        if (arr[i].second.first == true)
        {
            left += arr[i].second.second;
        }
        else
        {
            right -= arr[i].second.second;
        }
    }
	
    cout << ans << endl;
	return 0;
}