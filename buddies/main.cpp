#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct fman
{
    int st, end;
};

bool comp(fman a, fman b)
{
    return a.end < b.end;
}

int main()
{
    int c, n, i, tmp, tmpend, ct = 0;
    cin >> c >> n;
    multiset<int> s;
    for (i = 0; i < c; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    vector<fman> freshm;
    for (i = 0; i < n; i++)
    {
        cin >> tmp >> tmpend;
        freshm.push_back({tmp, tmpend});
    }
    sort(freshm.begin(), freshm.end(), comp);
    for (i = 0; i < freshm.size(); i++)
    {
        if (s.lower_bound(freshm[i].st) == s.end())
            continue;
        if (*s.lower_bound(freshm[i].st) <= freshm[i].end)
        {
            ct++;
            s.erase(s.lower_bound(freshm[i].st));
        }
    }
    cout << ct;
    system("pause");
    return 0;
}