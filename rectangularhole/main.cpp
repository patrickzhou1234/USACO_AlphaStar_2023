// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n, b, s = 0, res = MAX_INT;

void gen(int i, int a[])
{
    if (s >= b)
    {
        res = min(s - b, res);
        return;
    }
    if (i == n)
    {
        return;
    }
    gen(i + 1, a);
    s += a[i];
    gen(i + 1, a);
    s -= a[i];
}

int main()
{
    int i;
    cin >> n >> b;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    gen(0, a);
    cout << res;
    system("pause");
    return 0;
}