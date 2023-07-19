// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441857&cmid=79056
#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, mx, p, nxtX, i;
    cin >> n;
    mx = 3 * n + 1;
    int stps[mx];
    for (i = 0; i < mx; i++)
    {
        stps[i] = -1;
    }
    queue<int> q;
    stps[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        nxtX = p - 1;
        if (0 < nxtX && nxtX < mx && stps[nxtX] == -1)
        {
            stps[nxtX] = stps[p] + 1;
            q.push(nxtX);
        }
        nxtX = p + 1;
        if (0 < nxtX && nxtX < mx && stps[nxtX] == -1)
        {
            stps[nxtX] = stps[p] + 1;
            q.push(nxtX);
        }
        nxtX = p * 3;
        if (0 < nxtX && nxtX < mx && stps[nxtX] == -1)
        {
            stps[nxtX] = stps[p] + 1;
            q.push(nxtX);
        }
    }
    cout << stps[n];
    system("pause");
    return 0;
}