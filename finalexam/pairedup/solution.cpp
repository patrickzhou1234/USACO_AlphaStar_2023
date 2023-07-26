// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=446118&cmid=78375
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, x, y, lw, up;
    cin >> n;
    vector<int> v, pairs;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (j = 0; j < x; j++)
        {
            v.push_back(y);
        }
    }
    sort(v.begin(), v.end());
    lw = 0, up = n - 1;
    while (lw < up)
    {
        if (a[lw] + a[up] > s)
        {
            up--;
        }
        else
        {
            ct += up - lw;
            lw++;
        }
    }
    system("pause");
    return 0;
}