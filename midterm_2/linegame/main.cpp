// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, bal, ct;
    cin >> n;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        arr.push_back(j);
    }
    bal = 0, i = 0, ct = 0;
    while (!arr.empty())
    {
        ct++;
        if (i >= arr.size())
        {
            i--;
            continue;
        }
        if (arr[i] > 0)
        {
            bal += arr[i];
            arr.erase(arr.begin() + i);
        }
        else if (arr[i] + bal > 0)
        {
            bal -= arr[i];
            arr.erase(arr.begin() + i);
        }
        else
        {
            i++;
        }
    }
    cout << ct;
    system("pause");
    return 0;
}