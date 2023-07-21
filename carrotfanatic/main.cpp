// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=443532&cmid=80126&page=1#
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, k, i, r = 0, res;
    cin >> n >> k;
    int a[n], sizeL[n], sizeR[n], bestL[n], bestR[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        while (r < n && a[r] - a[i] <= k)
        {
            sizeL[r] = r - i + 1;
            r++;
        }
        sizeR[i] = r - i;
    }
    bestL[0] = sizeL[0];
    for (i = 1; i < n; i++)
    {
        bestL[i] = max(sizeL[i], bestL[i - 1]);
    }
    bestR[n - 1] = sizeR[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        bestR[i] = max(sizeR[i], bestR[i + 1]);
    }
    res = 0;
    for (i = 1; i < n; i++)
    {
        res = max(bestL[i - 1] + bestR[i], res);
    }
    cout << res;
    system("pause");
    return 0;
}