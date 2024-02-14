#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int y;
    cin >> y;

    while (true)
    {
        int nums[10] = {};
        y++;
        string yStr = to_string(y);
        for (char digit : yStr)
        {
            nums[digit - '0']++;
        }
        
        bool found = false;
        for (int num : nums)
        {
            if (num > 1)
            {
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            cout << y << endl;
            break;
        }
    }
	
	return 0;
}