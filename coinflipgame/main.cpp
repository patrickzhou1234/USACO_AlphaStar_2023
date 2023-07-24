// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n, j;

void gen(int i, int a[])
{
    if (i == n)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << "\n";
        return;
    }
    a[i] = 0;
    gen(i + 1, a);
    a[i] = 1;
    gen(i + 1, a);
}

int main()
{
    cin >> n;
    int a[n];
    gen(0, a);
    system("pause");
    return 0;
}