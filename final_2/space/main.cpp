#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10;
const int INF = 1e9 + 7;
int destructionTime[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int t)
{
    if (x < 0 || y < 0 || x >= MAX || y >= MAX || visited[x][y] || t >= destructionTime[x][y])
    {
        return;
    }
    visited[x][y] = true;
    dist[x][y] = t;
    for (int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i], t + 1);
    }
    visited[x][y] = false;
}

int main()
{
    int A, x, y, t;
    cin >> A;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            destructionTime[i][j] = INF;
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < A; i++)
    {
        cin >> x >> y >> t;
        destructionTime[x][y] = min(destructionTime[x][y], t);
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX)
                destructionTime[nx][ny] = min(destructionTime[nx][ny], t);
        }
    }

    dfs(0, 0, 0);
    int ans = INF;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (destructionTime[i][j] > dist[i][j])
                ans = min(ans, dist[i][j]);
        }
    }

    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
