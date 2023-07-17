// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=439991&cmid=78318&page=1#
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct part
{
    double accel;
    int ind, f, m;
};

bool comp(part a, part b)
{
    return a.accel > b.accel;
}

int main()
{
    int f, m, n, i, ftmp, mtmp;
    cin >> f >> m >> n;
    part parts[n];
    for (i = 0; i < n; i++)
    {
        cin >> ftmp >> mtmp;
        parts[i].accel = (double)ftmp / mtmp;
        parts[i].ind = i + 1;
        parts[i].f = ftmp;
        parts[i].m = mtmp;
    }
    sort(parts, parts + n, comp);
    vector<int> res;
    for (i = 0; i < n; i++)
    {
        if (parts[i].accel > (double)f / m)
        {
            res.push_back(parts[i].ind);
            f += parts[i].f;
            m += parts[i].m;
        }
    }
    sort(res.begin(), res.end());
    for (i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    if (res.size() == 0)
    {
        cout << "NONE" << endl;
    }
    system("pause");
    return 0;
}