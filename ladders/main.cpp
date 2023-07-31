#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647

struct coords
{
    int r, c;
};

const int sz = 3000;
bool wall = true;
int dr[4][4] = {-1, 0, 0, 1}, dc[4][4] = {0, -1, 1, 0};
bool visited[sz][sz], grid[sz][sz];

bool inBounds(int r, int c)
{
    return r >= 0 && r < sz && c >= 0 && c < sz;
}

void floodfill(int r, int c)
{
    queue<coords> q;
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty())
    {
        int pr = q.front().r, pc = q.front().c, i, nextR, nextC;
        q.pop();
        for (i = 0; i < 4; i++)
        {
            nextR = pr + dc[i], nextC = pc + dc[i];
            if (inBounds(nextR, nextC) && !visited[nextR][nextC] && grid[nextR][nextC] != wall)
                q.push({nextR, nextC}), visited[nextR][nextC] = true;
        }
    }
}

int main()
{

    system("pause");
    return 0;
}