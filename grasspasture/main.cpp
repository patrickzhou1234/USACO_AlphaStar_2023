#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647

int n, tMax;

bool isValid(int k, int dur[])
{
    priority_queue<int, vector<int>, greater<int>> q;
    int i = 0, res, fTime;
    while (i < k)
    {
        q.push(dur[i]);
        i++;
    }
    res = 0;
    while (!q.empty())
    {
        fTime = q.top();
        q.pop();
        res = max(fTime, res);
        if (i < n)
        {
            q.push(fTime + dur[i]);
            i++;
        }
    }
    return res <= tMax;
}

int main()
{
    int i, lo, hi, k, res;
    cin >> n >> tMax;
    int dur[n];
    for (i = 0; i < n; i++)
    {
        cin >> dur[i];
    }
    lo = 1, hi = n, res = n;
    while (lo <= hi)
    {
        k = (lo + hi) / 2;
        if (isValid(k, dur))
        {
            res = k;
            hi = k - 1;
        }
        else
        {
            lo = k + 1;
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}