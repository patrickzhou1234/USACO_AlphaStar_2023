#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, tmp, ct = 0;
    bool fd;
    cin >> n;
    vector<int> a, b;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    for (i = 1; i <= 2 * n; i++)
    {
        fd = false;
        for (j = 0; j < n; j++)
        {
            if (b[j] == i)
            {
                fd = true;
                break;
            }
        }
        if (!fd)
        {
            a.push_back(i);
        }
    }
    sort(a.begin(), a.end());
    for (j = 0; j < b.size(); j++)
    {
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] > b[j])
            {
                ct++;
                a.erase(a.begin() + i);
                break;
            }
        }
    }
    cout << ct;
    system("pause");
    return 0;
}