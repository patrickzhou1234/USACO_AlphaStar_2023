// link to problem
#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647
#define WATER 0
#define ROCK 2

struct unit
{
    int pr, pc;
};

int main()
{
    int m, n, m1, m2, sX, sY, eX, eY, i, j, pr, pc, nxtR, nxtC;
    bool inBounds;
    cin >> m >> n >> m1 >> m2;
    int fore[m][n];
    int dr[8] = {-m2, -m2, -m1, -m1, m1, m1, m2, m2}, dc[8] = {-m1, m1, -m2, m2, -m2, m2, -m1, m1};
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> fore[i][j];
            if (fore[i][j] == 3)
            {
                sX = i;
                sY = j;
            }
            else if (fore[i][j] == 4)
            {
                eX = i;
                eY = j;
            }
        }
    }
    int distances[m][n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            distances[i][j] = -1;
    queue<unit> q;
    q.push({sX, sY});
    distances[sX][sY] = 0;
    while (!q.empty())
    {
        pr = q.front().pr, pc = q.front().pc;
        q.pop();
        if (pr == eX && pc == eY)
        {
            cout << distances[pr][pc];
            break;
        }
        for (i = 0; i <= 7; i++)
        {
            nxtR = pr + dr[i], nxtC = pc + dc[i];
            inBounds = nxtR >= 0 && nxtR < m && nxtC >= 0 && nxtC < n;
            if (inBounds && fore[nxtR][nxtC] != WATER && fore[nxtR][nxtC] != ROCK && distances[nxtR][nxtC] == -1)
            {
                distances[nxtR][nxtC] = distances[pr][pc] + 1;
                q.push({nxtR, nxtC});
            }
        }
    }
    system("pause");
    return 0;
}