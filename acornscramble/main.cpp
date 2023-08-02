// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, ct = 0, len = 0, curPos, curLen;
    cin >> n;
    int a[n], b[n], indexA[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        indexA[a[i]] = i;
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    bool vis[n];
    for (i = 0; i < n; i++)
        vis[i] = false;
    for (i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        curPos = i;
        curLen = 0;
        while (!vis[curPos])
        {
            vis[curPos] = true;
            curPos = indexA[b[curPos]];
            curLen++;
        }
        if (curLen > 1)
        {
            len = max(len, curLen);
            ct++;
        }
    }
    if (len == 0)
    {
        len = -1;
    }
    cout << ct << " " << len;
    system("pause");
    return 0;
}