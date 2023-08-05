// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct edge
{
    int first, second;
};

int n, qbig, ct = 0;
vector<edge> adjLs[5000];

void dfs(int u, int par, int k)
{
    ct++;
    for (edge v : adjLs[u])
    {
        if (v.first != par && v.second >= k)
            dfs(v.first, u, k);
    }
}

int main()
{
    int i, p, q, r, v, k;
    cin >> n >> qbig;
    for (i = 0; i < n; i++)
    {
        cin >> p >> q >> r;
        q--;
        p--;
        adjLs[p].push_back(make_pair(q, r));
        adjLs[q].push_back(make_pair(p, r));
    }
    for (i = 0; i < qbig; i++)
    {
        cin >> v >> k;
        v--;
        dfs(v, -1, k);
        cout << ct << endl;
    }
    system("pause");
    return 0;
}