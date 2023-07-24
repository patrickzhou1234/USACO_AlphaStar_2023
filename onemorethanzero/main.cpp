// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n, cntOnes = 0, ct = 0;

void gen(int i, int a[])
{
    if (i - cntOnes >= (n + 1) / 2)
    {
        return;
    }
    if (i == n)
    {
        if (cntOnes > n - cntOnes)
        {
            for (int s = 0; s < n; s++)
            {
                cout << a[s];
            }
            cout << "\n";
            ct++;
            return;
        }
    }
    a[i] = 0;
    gen(i + 1, a);
    cntOnes++;
    a[i] = 1;
    gen(i + 1, a);
    cntOnes--;
}

int main()
{
    cin >> n;
    int a[n];
    gen(0, a);
    cout << ct;
    system("pause");
    return 0;
}