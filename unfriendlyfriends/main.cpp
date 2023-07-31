// link to problem
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

bool comp(int a[][], int b[][])
{
    return a[0] < b[0];
}

int main()
{
    int n, k, i, photoStart, res;
    cin >> n >> k;
    int pairs[k][2];
    for (i = 0; i < k; i++)
    {
        cin >> pairs[i][0] >> pairs[i][1];
    }
    sort(pairs, pairs + k, comp);
    photoStart = 1;
    res = 0;
    for (i = 0; i < k; i++)
    {
        if (photoStart <= pairs[i][0])
        {
            res += pairs[i][1] - pairs[i][0] + 1;
            photoStart = pairs[i][1];
        }
    }
    cout << res;
    system("pause");
    return 0;
}