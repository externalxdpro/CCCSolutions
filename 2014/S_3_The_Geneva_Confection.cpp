#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int n;
        cin >> n;
        stack<int> mtntop = {};
        stack<int> branch = {};

        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            mtntop.push(input);
        }
        
        int j = 1;
        bool impossible = false;
        while (j <= n)
        {
            if (!mtntop.empty() && mtntop.top() == j)
            {
                mtntop.pop();
                j++;
            }
            else if (!branch.empty() && branch.top() == j)
            {
                branch.pop();
                j++;
            }
            else
            {
                if (mtntop.empty())
                {
                    impossible = true;
                    break;
                }

                branch.push(mtntop.top());
                mtntop.pop();
            }
        }
        if (impossible) cout << "N" << endl;
        else cout << "Y" << endl;
    }
	
	return 0;
}