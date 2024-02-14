#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<char> student;
    vector<char> correct;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char response;
        cin >> response;
        student.push_back(response);
    }

    for (int i = 0; i < n; i++) {
        char response;
        cin >> response;
        correct.push_back(response);
    }

    int c = 0;
    for (int i = 0; i < student.size(); i++) {
        if (student[i] == correct[i]) {
            c++;
        }
    }

    cout << c << endl;
    return 0;
}
