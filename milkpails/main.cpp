// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441916&cmid=79059&page=1
#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647

struct unit
{
    int x, y, k;
};

int main()
{
    int x, y, k, m, i, j, px, py, pk, transf, res;
    cin >> x >> y >> k >> m;
    bool visited[x + 1][y + 1];
    for (i = 0; i < x + 1; i++)
        for (int j = 0; j < y + 1; j++)
            visited[i][j] = false;
    queue<unit> q;
    unit tmp;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        px = tmp.x, py = tmp.y, pk = tmp.k;
        if (pk > k)
            continue;
        if (visited[px][py])
            continue;
        visited[px][py] = true;
        pk++;
        q.push({x, py, pk});
        q.push({px, y, pk});
        q.push({0, py, pk});
        q.push({px, 0, pk});
        transf = min(x - tmp.x, tmp.y);
        q.push({px + transf, py - transf, pk});
        transf = min(tmp.x, y - tmp.y);
        q.push({px - transf, py + transf, pk});
    }
    res = x + y;
    for (i = 0; i < x + 1; i++)
    {
        for (j = 0; j < y + 1; j++)
        {
            if (visited[i][j])
            {
                res = min(abs(m - i - j), res);
            }
        }
    }
    cout << res;
    system("pause");
    return 0;
}