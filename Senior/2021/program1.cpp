// 15/15 marks
#include <iostream>
#include <vector>

using namespace std;

vector<int> split(string s, char delimiter = ' ')
{
    int current;
    int next = -1;

    vector<string> temp;
    do
    {
        current = next + 1;
        next = s.find_first_of(delimiter, current);
        temp.push_back(s.substr(current, next - current));
    } while (next != string::npos);

    vector<int> result = {};
    for (string num: temp)
    {
        result.push_back(stoi(num));
    }

    return result;
}

int main()
{
    int n;
    vector<double> heights;
    vector<double> widths;
    double input;

    cin >> n;

    for (int i = 0; i < n + 1; i++)
    {
        cin >> input;
        heights.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        widths.push_back(input);
    }

    double result = 0;
    for (int i = 1; i < size(heights); i++)
    {
        result += (heights[i] + heights[i - 1]) / 2 * widths[i - 1];
    }

    cout << fixed << result << endl;

    return 0;
}
