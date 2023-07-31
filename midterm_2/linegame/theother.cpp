#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> students(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> students[i].second;
        students[i].first = i;
    }

    sort(students.begin(), students.end());

    priority_queue<int> pq;
    long long res = 0;
    for (int i = 0; i < N; ++i)
    {
        if (students[i].second > 0)
        {
            pq.push(students[i].second);
        }
        else
        {
            while (!pq.empty() && students[i].second < 0)
            {
                int popped = pq.top();
                pq.pop();
                int add = min(-students[i].second, popped);
                students[i].second += add;
                popped -= add;
                if (popped > 0)
                {
                    pq.push(popped);
                }
                res += 2 * (long long)add;
            }
            if (pq.empty() && students[i].second < 0)
            {
                res += 2 * (long long)-students[i].second;
                students[i].second = 0;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
