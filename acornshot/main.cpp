// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=440264&cmid=79054&page=1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483647

vector<int> targets;
int k;

bool isValid(int r)
{
    int acorns = 0, i;
    int lastThrown = MIN_INT;
    for (i = 0; i < targets.size(); i++)
    {
        if (targets[i] - r <= targets[i] && targets[i] <= lastThrown + r)
        {
            continue;
        }
        lastThrown = targets[i] + r;
        acorns++;
    }
    return acorns <= k;
}

int main()
{
    int n, i, tmp, res, lo, hi, mid;
    cin >> n >> k;
    int x[n];
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        targets.push_back(tmp);
    }
    sort(targets.begin(), targets.end());
    lo = 1, hi = targets[n - 1], mid;
    res = hi;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (isValid(mid))
        {
            res = mid;
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << res << "\n";
    system("pause");
    return 0;
}