#include <unordered_set>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct conn
{
    int t1, t2;
};

int n, m;

unordered_set<int> dfs(int f, conn conns[], unordered_set<int> visnums, unordered_set<int> res)
{
    int i;
    if (visnums.find(f) != visnums.end())
    {
        return res;
    }
    visnums.insert(f);
    for (i = 0; i < m; i++)
    {
        if (conns[i].t1 == f)
        {
            res.insert(conns[i].t2);
            unordered_set<int> tmp = dfs(conns[i].t2, conns, visnums, res);
            res.insert(tmp.begin(), tmp.end());
        }
        if (conns[i].t2 == f)
        {
            res.insert(conns[i].t1);
            unordered_set<int> tmp = dfs(conns[i].t1, conns, visnums, res);
            res.insert(tmp.begin(), tmp.end());
        }
    }
    return res;
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
    unordered_set<int> visnums, res;
    res = dfs(1, conns, visnums, res);
    for (i = 2; i <= n; i++)
    {
        if (res.find(i) == res.end())
        {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}