#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n, ct = 0;

bool adjMatrix[200][200];

void dfs(int u, int x[], int y[], int p[], bool visited[])
{
    int v;
    ct++;
    visited[u] = true;
    for (v = 0; v < n; v++)
    {
        if (!visited[v] && adjMatrix[u][v])
            dfs(v, x, y, p, visited);
    }
}

int main()
{
    int i, j, dx, dy, res;
    cin >> n;
    int x[n], y[n], p[n];
    bool visited[n];
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> p[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                adjMatrix[i][j] = false;
            else
            {
                dx = x[i] - x[j];
                dy = y[i] - y[j];
                adjMatrix[i][j] = dx * dx + dy * dy <= p[i] * p[i];
            }
        }
    }
    res = 0;
    for (i = 0; i < n; i++)
    {
        ct = 0;
        for (j = 0; j < n; j++)
        {
            visited[j] = false;
        }
        dfs(i, x, y, p, visited);
        res = max(res, ct);
    }
    cout << res;
    system("pause");
    return 0;
}