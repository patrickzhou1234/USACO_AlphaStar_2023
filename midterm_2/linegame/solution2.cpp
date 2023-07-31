// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, bal;
    cin >> n;
    vector<int> main;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        main.push_back(j);
    }
    bool fd = false;
    for (i = 0; i < n; i++)
    {
        if (main[i] > 0 && !fd)
        {
            bal += main[i];
        }
        else if (main[i] > 0 && fd)
        {
            bal += main[i];
        }

        else
        {
            fd = true;
            if (main[i] + bal > 0)
                bal -= main[i];
            else
                fd = false;
        }
    }
    system("pause");
    return 0;
}