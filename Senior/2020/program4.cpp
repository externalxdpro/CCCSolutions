#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int groupA = 0, groupB = 0, groupC = 0;

void groupAdd(char group)
{
    if (group == 'A') groupA++;
    else if (group == 'B') groupB++;
    else if (group == 'C') groupC++;
}
void groupRm(char group)
{
    if (group == 'A') groupA--;
    else if (group == 'B') groupB--;
    else if (group == 'C') groupC--;
}

int main()
{
    string s;
    cin >> s;

}