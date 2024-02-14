#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<char, int> count(string word)
{
    map<char, int> freqs;
    for (char letter : word)
    {
        if (freqs.find(letter) != freqs.end())
        {
            freqs[letter]++;
            continue;
        }
        freqs.insert(make_pair(letter, 1));
    }

    return freqs;
}

int main()
{
    string n, h;
    cin >> n >> h;

    if (n.size() > h.size())
    {
        cout << 0 << endl;
        return 0;
    }

    map<char, int> freqsN = count(n);
    map<char, int> freqsSubstr = count(h.substr(0, n.size()));
    set<string> found;

    for (int i = 0; i <= (h.size() - n.size()); i++)
    {
        if (freqsN == freqsSubstr) found.insert(h.substr(i, n.size()));

        freqsSubstr[h[i + n.size()]]++;
        freqsSubstr[h[i]]--;
        if (freqsSubstr[h[i]] == 0) freqsSubstr.erase(h[i]);
    }

    cout << found.size() << endl;
    return 0;
}