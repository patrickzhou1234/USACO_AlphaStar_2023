// http://www.usaco.org/index.php?page=viewproblem2&cpid=1280
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, pos = 0, sum = 0;
    string s = "";
    cin >> n;
    int a[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    a[n] = 0;
    while (s.length() < sum)
    {
        while (a[pos] > 0)
        {
            s += 'R';
            a[pos]--;
            pos++;
        }
        while (pos > 0 && (a[pos - 1] > 1 || a[pos] == 0))
        {
            s += 'L';
            pos--;
            a[pos]--;
        }
    }
    cout << s;
    system("pause");
    return 0;
}