// link to problem
#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647
#define ROCK '*'

struct unit
{
    int r, c, dist;
};

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};

int main()
{
    int r, c, i, j, pr, pc, dist;
    bool inBounds;
    cin >> r >> c;
    char grid[r][c];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> grid[i][j];
    bool visited[r][c];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            visited[i][j] = false;
    queue<unit> q;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        pr = q.front().r;
        pc = q.front().c;
        dist = q.front().dist;
        q.pop();
        inBounds = pr >= 0 && pr < r && pc >= 0 && pc < c;
        if (!inBounds || visited[pr][pc] || grid[pr][pc] == ROCK)
            continue;
        visited[pr][pc] = true;
        if (grid[pr][pc] == 'C')
        {
            cout << dist;
            return 0;
        }
        for (i = 0; i < 4; i++)
            q.push({pr + dr[i], pc + dc[i], dist + 1});
    }
    return 0;
}