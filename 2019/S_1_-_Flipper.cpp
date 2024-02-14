#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int grid[2][2] = {{1, 2}, {3, 4}};

void hFlip ()
{
    int temp;
    temp = grid[0][0];
    grid[0][0] = grid[1][0];
    grid[1][0] = temp;

    temp = grid[0][1];
    grid[0][1] = grid[1][1];
    grid[1][1] = temp;
}

void vFlip()
{
    int temp;
    temp = grid[0][0];
    grid[0][0] = grid[0][1];
    grid[0][1] = temp;

    temp = grid[1][0];
    grid[1][0] = grid[1][1];
    grid[1][1] = temp;
}

int main()
{
    string input;
    cin >> input;

    for (char letter : input)
    {
        if (letter == 'H') hFlip();
        else if (letter == 'V') vFlip();
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}