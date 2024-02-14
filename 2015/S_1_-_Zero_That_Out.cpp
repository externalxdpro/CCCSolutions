#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int k;
    cin >> k;
    vector<int> nums;

    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;

        if (input == 0) nums.pop_back();
        else nums.push_back(input);
    }

    int total = 0;
    for (int num : nums)
    {
        total += num;
    }
    
    cout << total << endl;
	return 0;
}