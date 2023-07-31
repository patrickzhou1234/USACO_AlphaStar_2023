// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct unit
{
    int val;
    bool dealed;
};

int main()
{
    int n, i, j, bal, ct, k;
    cin >> n;
    vector<unit> arr;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        arr.push_back({j, false});
    }
    bal = 0, i = 0, ct = 0, k = 0;
    while (k != n)
    {
        if (i >= arr.size())
        {
            i--;
            continue;
        }
        ct++;
        if (!arr[i].dealed)
        {
            if (arr[i].val > 0)
            {
                bal += arr[i].val;
                arr[i].dealed = true;
                k++;
            }
            else if (arr[i].val + bal > 0)
            {
                bal -= arr[i].val;
                arr[i].dealed = true;
                k++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i--;
        }
    }
    cout << ct;
    system("pause");
    return 0;
}