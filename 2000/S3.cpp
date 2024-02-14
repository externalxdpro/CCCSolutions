#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    unordered_map<string, unordered_set<string>> links;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string pageLink;
        cin >> pageLink;

        string line;
        while (true) {
            getline(cin, line);
            if (line.find("<A") != string::npos) {
                int aTagPos = line.find("<A");
                int aTagEndPos = line.find(">", aTagPos) + 1;
                string aTag = line.substr(aTagPos, aTagEndPos - aTagPos);

                int linkPos = aTag.find("\"");
                int linkEndPos = aTag.find("\"", linkPos + 1) - 1;
                string link = aTag.substr(linkPos + 1, linkEndPos - linkPos);

                links[pageLink].insert(link);
            }

            if (line.find("</HTML>") != string::npos) {
                break;
            }
        }
    }

    for (auto [key, val] : links) {
        cout << key << ": ";
        for (string j : val) {
            cout << j << ',';
        }
        cout << endl;
    }

    while (true) {
        string orig, target;
        getline(cin, orig);
        if (orig == "The End") {
            break;
        }
        getline(cin, target);
    }

    return 0;
}
