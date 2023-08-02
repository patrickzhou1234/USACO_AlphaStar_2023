#include <queue>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, removed, p;
    cin >> n;
    int next[n + 1], inDegrees[n + 1];
    for (i = 0; i < n + 1; i++)
        inDegrees[i] = 0;
    for (i = 1; i < n + 1; i++)
    {
        cin >> next[i];
        inDegrees[next[i]]++;
    }
    queue<int> q;
    for (i = 1; i < n + 1; i++)
        if (inDegrees[i] == 0)
            q.push(i);
    removed = 0;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        removed++;
        inDegrees[next[p]]--;
        if (inDegrees[next[p]] == 0)
            q.push(next[p]);
    }
    cout << n - removed << endl;
    system("pause");
    return 0;
}