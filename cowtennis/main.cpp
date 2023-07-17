// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=440402&cmid=79055&page=1
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    long long n, i, ct = 0, cw1, cw2, dx, lPos, uPos;
    cin >> n;
    long long cows[n];
    for (i = 0; i < n; i++)
        cin >> cows[i];
    sort(cows, cows + n);
    for (cw1 = 0; cw1 < n; cw1++)
    {
        for (cw2 = cw1 + 1; cw2 < n; cw2++)
        {
            dx = cows[cw2] - cows[cw1];
            lPos = cows[cw2] + dx;
            uPos = cows[cw2] + 2 * dx;
            ct += upper_bound(cows, cows + n, uPos) - lower_bound(cows, cows + n, lPos);
        }
    }
    cout << ct;
    return 0;
}