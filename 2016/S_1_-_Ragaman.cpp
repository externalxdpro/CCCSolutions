#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> count(string str)
{
    vector<int> result(27);
    for (char letter : str)
    {
        if (letter == '*')
        {
            result[26]++;
            continue;
        }

        int index = letter - 97;
        result[index]++;
    }

    return result;
}

int main()
{
    cin.sync_with_stdio(0);
	cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    vector<int> count1 = count(str1);
    vector<int> count2 = count(str2);

    if (count1 == count2)
    {
        std::cout << "A" << endl;
        return 0;
    }

    int difference = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] == count2[i]) continue;

        difference += abs(count1[i] - count2[i]);
    }

    if (difference == count2[26])
    {
        std::cout << "A" << endl;
        return 0;
    }

    std::cout << "N" << endl;
	return 0;
}