#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 5)
    {
        cout << n / 2 + 1 << endl;
    }
    else
    {
        if (n == 6)
        {
            cout << 3 << endl;
        }
        else if (n == 7 || n == 8)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    
    return 0;
}