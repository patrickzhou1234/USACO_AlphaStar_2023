// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j;
    cin >> n;
    int a[n], res[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        res[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                res[i] = j + 1;
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
        cout << res[i] << "\n";
    system("pause");
    return 0;
}