#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n + 2);
    vector<long long> pos(n + 2), leftMax(n + 2, 0), rightMax(n + 2, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i; // store position of each height
    }

    for (int i = 2; i <= n; ++i)
    {
        leftMax[i] = max(leftMax[i - 1], pos[i - 1]); // prefix maximum
    }

    for (int i = n - 1; i >= 1; --i)
    {
        rightMax[i] = max(rightMax[i + 1], pos[i + 1]); // suffix maximum
    }

    long long result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += (long long)(pos[i] - leftMax[i] + 1) * i;
        result += (long long)(rightMax[i] - pos[i] + 1) * (n - i + 1);
    }

    cout << result << endl;

    return 0;
}
