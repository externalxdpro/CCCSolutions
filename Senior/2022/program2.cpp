#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string s, char delimiter = ' ')
{
    int current;
    int next = -1;

    vector<string> result;

    do
    {
        current = next + 1;
        next = s.find_first_of(delimiter, current);
        result.push_back(s.substr(current, next - current));
    } while (next != string::npos);
    

    return result;
}

int goodGroups()
{
    vector<vector<string>> togetherGroups;
    vector<vector<string>> seperateGroups;
    vector<vector<string>> groups;
    int violations = 0;
    int x, y, g;

    cin >> x;
    for (int i = 0; i < x; i++)
    {
        string name1, name2;
        cin >> name1 >> name2;
        togetherGroups.push_back({name1, name2});
    }
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        string name1, name2;
        cin >> name1 >> name2;
        seperateGroups.push_back({name1, name2});
    }
    cin >> g;
    for (int i = 0; i < g; i++)
    {
        string temp;
        getline(cin, temp);
        groups.push_back(split(temp));
    }

    for (int togetherIndex = 0; togetherIndex < size(togetherGroups); togetherIndex++)
    {
        for (int i = 0; i < size(groups); i++)
        {
            bool found = false;
            for (int j = 0; j < size(groups[i]); j++)
            {
                if (groups[i][j] == togetherGroups[togetherIndex][0]) found = true;
            }

            if (!found) continue;

            bool together = false;
            for (int j = 0; j < size(groups[i]); j++)
            {
                if (groups[i][j] == togetherGroups[togetherIndex][1])
                {
                    together = true;
                    break;
                }
            }
            if (!together)
            {
                violations++;
                break;
            }
        }
    }

    for (int seperateIndex = 0; seperateIndex < size(seperateGroups); seperateIndex++)
    {
        for (int i = 0; i < size(groups); i++)
        {
            bool found = false;
            for (int j = 0; j < size(groups[i]); j++)
            {
                if (groups[i][j] == seperateGroups[seperateIndex][0]) found = true;
            }

            if (!found) continue;

            for (int j = 0; j < size(groups[i]); j++)
            {
                if (groups[i][j] == seperateGroups[seperateIndex][1])
                {
                    violations++;
                    break;
                }
            }
        }
    }


    return violations;
}

int main()
{
    cout << goodGroups() << endl;
}
