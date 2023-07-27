#include <vector>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n;
vector<int> a, aux;

void merge(int l, int lr, int r)
{
    int il = l, ir = lr + 1, iaux, i;
    aux.clear();
    while (il <= lr || ir <= r)
    {
        if (il > lr || (ir <= r && a[ir] < a[il]))
        {
            aux.push_back(a[ir]);
            ir++;
        }
        else
        {
            aux.push_back(a[il]);
            il++;
        }
    }
    iaux = 0;
    for (i = l; i <= r; i++)
    {
        a[i] = aux[iaux];
        iaux++;
    }
}

void mergesort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int m = (l + r) / 2, i;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    mergesort(0, n - 1);
    system("pause");
    return 0;
}