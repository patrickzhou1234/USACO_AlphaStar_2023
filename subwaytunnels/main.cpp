#include <unordered_set>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct conn
{
    int t1, t2;
};

int n, m;

unordered_set<int> res;

void dfs(int f, conn conns[])
{
    int i;
    if (res.find(f) != res.end())
    {
        return;
    }
    res.insert(f);
    for (i = 0; i < m; i++)
    {
        if (conns[i].t1 == f)
        {
            dfs(conns[i].t2, conns);
        }
        if (conns[i].t2 == f)
        {
            dfs(conns[i].t1, conns);
        }
    }
    return;
}

int main()
{
    int i;
    cin >> n >> m;
    conn conns[m];
    for (i = 0; i < m; i++)
    {
        cin >> conns[i].t1 >> conns[i].t2;
    }
    dfs(1, conns);
    bool fd = false;
    for (i = 2; i <= n; i++)
    {
        if (res.find(i) == res.end())
        {
            fd = true;
            cout << i << endl;
        }
    }
    if (!fd)
    {
        cout << 0;
    }
    system("pause");
    return 0;
}