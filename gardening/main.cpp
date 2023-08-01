// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n;
    cin >> n;
    int deg[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        deg[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    int mx = -MAX_INT;
    for (int i = 0; i < n + 1; i++)
    {
        mx = max(deg[i], mx);
    }
    cout << mx + 1 << endl;
    system("pause");
    return 0;
}