#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    int result = 91 + num1 * 1 + num2 * 3 + num3 * 1;
    cout << "The 1-3-sum is " << result << endl;
	
	return 0;
}