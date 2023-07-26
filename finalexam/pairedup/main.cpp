// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=446118&cmid=78375
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, x, y, mx = -MAX_INT;
    cin >> n;
    vector<int> v, pairs;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (j = 0; j < x; j++)
        {
            v.push_back(y);
        }
    }
    sort(v.begin(), v.end());
    for (i = 0; i < v.size(); i++)
    {
        pairs.push_back(v[i] + v[v.size() - 1 - i]);
    }
    for (i = 0; i < pairs.size(); i++)
    {
        cout << pairs[i] << " ";
    }
    system("pause");
    return 0;
}