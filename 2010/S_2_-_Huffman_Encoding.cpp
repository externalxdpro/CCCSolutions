#include <bits/stdc++.h>
#include <iostream>
#include <ranges>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<char> letters;
    vector<string> seqs;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        char letter;
        string seq;

        cin >> letter >> seq;

        letters.push_back(letter);
        seqs.push_back(seq);
    }

    string final;
    cin >> final;

    string buffer = "";
    string result;
    for (char i : final) {
        buffer += i;

        for (int i = 0; i < seqs.size(); i++) {
            if (seqs[i] == buffer) {
                buffer = "";
                result += letters[i];
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
}
