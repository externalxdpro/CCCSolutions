#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const vector<int> split(const string &str, const char &delim)
{
	string buff = "";
	vector<int> output;
	
	for(auto n:str)
	{
		if(n != delim) buff += n;
        else if(n == delim && buff != "")
        {
            output.push_back(stoi(buff)); buff = "";
        }
	}
	if(buff != "") output.push_back(stoi(buff));
	
	return output;
}

void print0 (vector<vector<int>> grid)
{
    for (auto a : grid)
    {
        for (auto b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}

void print90 (vector<vector<int>> grid)
{
    for (int j = grid[0].size() - 1; j >= 0; j--)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void print180 (vector<vector<int>> grid)
{
    for (int i = grid.size() - 1; i >= 0; i--)
    {
        for (int j = grid[i].size() - 1; j >= 0 ; j--)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void print270 (vector<vector<int>> grid)
{
    for (int j = 0; j < grid[0].size(); j++)
    {
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    string s;
    getline(cin, s);
    n = stoi(s);
    
    vector<vector<int>> grid;

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        grid.push_back(split(s, ' '));
    }

    int i, j;
    if (grid[0][0] < grid[0][n - 1]) j = 0;
    else j = n - 1;
    if (grid[0][j] < grid[n - 1][j]) i = 0;
    else i = n - 1;

    if (i == 0 && j == 0) print0(grid);
    else if (i == 0 && j == n - 1) print90(grid);
    else if (i == n - 1 && j == n - 1) print180(grid);
    else if (i == n - 1 && j == 0) print270(grid);

    return 0;
}