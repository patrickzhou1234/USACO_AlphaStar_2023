// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
int w, h, cursize = 0;
char grid[1000][80];
bool visited[1000][80];

bool inBounds(int r, int c)
{
    if (r < 0 || r >= h || c < 0 || c >= w)
    {
        return false;
    }
    return true;
}

void floodfill(int r, int c)
{
    int i;
    if (!inBounds(r, c) || grid[r][c] == '.' || visited[r][c])
        return;
    visited[r][c] = true;
    cursize++;
    for (i = 0; i < 4; i++)
        floodfill(r + dr[i], c + dc[i]);
}

int main()
{
    cin >> w >> h;
    int i, j, maxSize = -1;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            cursize = 0;
            floodfill(i, j);
            maxSize = max(maxSize, cursize);
        }
    }
    cout << maxSize;
    system("pause");
    return 0;
}