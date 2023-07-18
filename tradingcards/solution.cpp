#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, b, i;
    cin >> n >> b;
    int c[n];
    for (i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    return 0;
}