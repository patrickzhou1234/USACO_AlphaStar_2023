// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441916&cmid=79059
#include <iostream>
#include <queue>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int a, b, n, p, curcolor, i, nxtclr;
    cin >> a >> b >> n >> p;
    int ls[n];
    for (i = 0; i < n; i++)
    {
        cin >> ls[i];
    }
    int res[p + 1];
    for (i = 0; i < p + 1; i++)
        res[i] = -1;
    queue<int> q;
    q.push(a);
    res[a] = 0;
    while (!q.empty())
    {
        curcolor = q.front();
        q.pop();
        for (i = 0; i < n; i++)
        {
            nxtclr = curcolor * ls[i] % p;
            if (res[nxtclr] == -1)
            {
                res[nxtclr] = res[curcolor] + 1;
                q.push(nxtclr);
            }
        }
    }
    cout << res[b];
    system("pause");
    return 0;
}