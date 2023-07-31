// link to problem
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, bal, ct, k, res = 0;
    cin >> n;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        arr.push_back(j);
    }
    priority_queue<int> pq;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pq.push(arr[i]);
        }
        else
        {
            while (!pq.empty() && arr[i] < 0)
            {
                int popped = pq.top();
                pq.pop();
                int add = min(abs(arr[i]), popped);
                arr[i] += add;
                popped -= add;
                if (popped > 0)
                {
                    pq.push(popped);
                }
                res += 2 * add;
            }
            if (pq.empty() && arr[i] < 0)
            {
                res += 2 * abs(i);
                arr[i] = 0;
            }
        }
    }
    cout << res;
    system("pause");
    return 0;
}