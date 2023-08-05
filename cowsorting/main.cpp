#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, gMin, res, curPos, lMin, len, sum, costLocal, costGlobal;
    cin >> n;
    int a[n], sortedA[n];
    bool vis[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sortedA[i] = a[i];
        vis[i] = false;
    }
    sort(sortedA, sortedA + n);
    gMin = sortedA[n - 1];
    res = 0;
    for (i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        curPos = i;
        lMin = MAX_INT;
        len = 0;
        sum = 0;
        while (!vis[curPos])
        {
            lMin = min(lMin, a[curPos]);
            sum += a[curPos];
            len++;
            vis[curPos] = true;
            curPos = lower_bound(sortedA, sortedA + n, a[curPos]) - sortedA;
        }
        if (len == 1)
        {
            continue;
        }
        costLocal = lMin * (len - 1) + (sum - lMin);
        sum = sum - lMin + gMin;
        costGlobal = (lMin + gMin) + (len - 1) * gMin + (sum - gMin) + (lMin + gMin);
        res += min(costLocal, costGlobal);
    }
    cout << res;
    system("pause");
    return 0;
}