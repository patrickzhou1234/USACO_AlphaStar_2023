// link to problem
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct pairr
{
    int x, y;
};

int main()
{
    vector<pairr> ld;
    bool flag;
    int n, i, j, m, mxel;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        ld.push_back({a[i], a[i + 1]});
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 2; j < n; j++)
        {
            mxel = *max_element(a + i + 1, a + j);
            if (mxel < a[i] && mxel < a[j])
            {
                ld.push_back({a[i], a[j]});
            }
        }
    }
    int ct = 0;
    for (i = 0; i < ld.size(); i++)
    {
        ct += abs(ld[i].x - ld[i].y) + 1;
    }
    cout << ct - 1;
    system("pause");
    return 0;
}