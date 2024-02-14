#include <iostream>
#include <map>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    map<int, int> rowActions = {};
    map<int, int> columnActions = {};
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        char rOrC;
        int num;
        cin >> rOrC >> num;
        if (rOrC == 'R')
        {
            if (rowActions.find(num) == rowActions.end())
            {
                rowActions.insert(pair<int, int>(num, 1));
            }
            else
            {
                rowActions[num] += 1;
            }
        }
        else
        {
            if (columnActions.find(num) == columnActions.end())
            {
                columnActions.insert(pair<int, int>(num, 1));
            }
            else
            {
                columnActions[num] += 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int total = rowActions[i + 1] + columnActions[j + 1];
            if (total % 2 == 1) result++;
        }
    }

    cout << result << endl;

    return 0;
}
