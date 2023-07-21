// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=443436&cmid=80118
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, s, i, lw, up, ct = 0;
    cin >> n >> s;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
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
    cout << ct;
    system("pause");
    return 0;
}