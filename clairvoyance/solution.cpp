// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, tmp, bcards = 0, res = 0;
    cin >> n;
    int b[2 * n + 1];
    for (i = 0; i <= 2 * n; i++)
    {
        b[i] = false;
    }
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        b[tmp] = true;
    }
    for (i = 1; i <= 2 * n; i++)
    {
        if (b[i])
        {
            bcards++;
        }
        else
        {
            if (bcards > 0)
            {
                bcards--;
                res++;
            }
        }
    }
    cout << res;
    system("pause");
    return 0;
}