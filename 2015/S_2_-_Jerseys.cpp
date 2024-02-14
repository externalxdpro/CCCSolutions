#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int j, a;
    cin >> j >> a;
    vector<int> jNums;

    for (int i = 0; i < j; i++)
    {
        char size;
        cin >> size;
        if (size == 'S') jNums.push_back(0);
        else if (size == 'M') jNums.push_back(1);
        else jNums.push_back(2);
    }
    
    int result = 0;
    
    for (int i = 0; i < a; i++)
    {
        char size;
        int num;
        cin >> size >> num;

        if (size == 'S' && jNums[num - 1] >= 0)
        {
            result++;
            jNums[num - 1] = -1;
        }
        else if (size == 'M' && jNums[num - 1] >= 1)
        {
            result++;
            jNums[num - 1] = -1;
        }
        else if (size == 'L' && jNums[num - 1] == 2)
        {
            result++;
            jNums[num - 1] = -1;
        }
    }

    cout << result << endl;

	return 0;
}