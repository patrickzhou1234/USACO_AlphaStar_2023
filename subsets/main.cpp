// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n, j;

void generate(int i, int a[], int msk[])
{
    bool fd = false;
    if (i == n)
    {

        for (j = 0; j < n; j++)
            if (msk[j] == 1)
                fd = true;

        if (!fd)
        {
            return;
        }
        for (j = 0; j < n; j++)
            if (msk[j] == 1)
                cout << a[j];
        cout << endl;
        return;
    }
    msk[i] = 0;
    generate(i + 1, a, msk);
    msk[i] = 1;
    generate(i + 1, a, msk);
}

int main()
{
    int i;
    cin >> n;
    int a[n];
    int msk[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    generate(0, a, msk);
    system("pause");
    return 0;
}