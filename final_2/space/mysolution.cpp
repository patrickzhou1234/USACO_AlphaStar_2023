// link to problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct blast
{
    int x, y, t;
};

vector<char[301][301]> grids;

string dfs(int x, int y, int t)
{
    if (grids[x + 1][y][t] != '#')
    {
        return dfs(x + 1, y, t + 1)
    }
    else if (grids[x - 1][y][t] != '#')
    {
        return dfs(x - 1, y, t + 1)
    }
    else if (grids[x][y + 1][t] != '#')
    {
        return dfs(x, y + 1, t + 1)
    }
    else if (grids[x][y - 1][t] != '#')
    {
        return dfs(x, y - 1, t + 1)
    }
    else
    {
        return t;
    }
}

int main()
{
    int n, i, mxT = -1;
    cin >> n;
    blast b[n], tCopy[n];
    for (i = 0; i < n; i++)
    {
        cin >> b[i].x >> b[i].y >> b[i].t;
        mxT = max(mxT, b[i].t);
    }
    sort(b, b + n, [](blast a, blast b)
         { return a.t < b.t; });
    char grid[301][301];
    copy(&grid[0][0], &grid[0][0] + 301 * 301, &tCopy[0][0]);
    sort(tCopy, tCopy + n, [](blast a, blast b)
         { return a.t < b.t; });
    for (i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
        {
            grid[i][j] = '.';
        }
    }
    for (i = 0; i < n; i++)
    {
        grid[b[i].x][b[i].y] = '#';
        grids.push_back(grid);
    }
    dfs(0, 0, 0);
    system("pause");
    return 0;
}