// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441857&cmid=79056
#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, k, mx, p, nxtX, i;
    cin >> n >> k;
    mx = 2 * k + 1;
    int stps[mx];
    for (i = 0; i < mx; i++)
    {
        stps[i] = -1;
    }
    queue<int> q;
    stps[n] = 0;
    q.push(n);
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
        nxtX = p * 2;
        if (0 < nxtX && nxtX < mx && stps[nxtX] == -1)
        {
            stps[nxtX] = stps[p] + 1;
            q.push(nxtX);
        }
    }
    cout << stps[k];
    system("pause");
    return 0;
}