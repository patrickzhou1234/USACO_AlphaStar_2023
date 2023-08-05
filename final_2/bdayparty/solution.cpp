#include <bits/stdc++.h>
using namespace std;

vector<int> adj[50005];
int component[50005];
bool visited[50005];

void dfs(int node, int c)
{
    visited[node] = true;
    component[node] = c;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            dfs(adj[node][i], c);
        }
    }
}

int main()
{
    int N, M, Q, u, v, comps = 1;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i, comps);
            comps++;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> u >> v;
        if (component[u] == component[v])
        {
            cout << "Y"
                 << "\n";
        }
        else
        {
            cout << "N"
                 << "\n";
        }
    }

    return 0;
}
