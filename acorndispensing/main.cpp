#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct coord
{
    int first, second;
};

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
int n, m;

int main()
{
    int i, j, px, py;
    cin >> n >> m;
    vector<coord> lev[n][m];
    for (i = 0; i < m; i++)
    {
        int r, c, l, k;
        cin >> r >> c >> l >> k;
        lev[r][c].push_back({l, k});
    }
    bool hasAcorns[n][n], vis[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            hasAcorns[i][j] = false;
            vis[i][j] = false;
        }
    }
    queue<coord> q;
    q.push({1, 1});
    hasAcorns[1][1] = vis[1][1] = true;
    while (!q.empty())
    {
        px = q.front().first - 1, py = q.front().second - 1;
        q.pop();
        for (i = 0; i < lev[px][py].size(); i++)
        {
            if (hasAcorns[lev[px][py][i].first][lev[px][py][i].second])
                continue;
            hasAcorns[lev[px][py][i].first][lev[px][py][i].second] = true;
            for (j = 0; j < 4; j++)
            {
                int nx = lev[px][py][i].first + dr[j], ny = lev[px][py][i].second + dc[j];
                if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny])
                    continue;
                vis[nx][ny] = true;
                q.push({lev[px][py][i].first, lev[px][py][i].second});
                break;
            }
        }
        for (i = 0; i < 4; i++)
        {
            int nx = px + dr[i], ny = py + dc[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny])
                continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    int ans = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (hasAcorns[i][j])
                ans++;
    cout << ans << endl;
    system("pause");
    return 0;
}