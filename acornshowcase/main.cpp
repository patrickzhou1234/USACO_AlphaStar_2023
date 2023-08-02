// link to problem
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define MAX_INT 2147483647

struct unit
{
    int num, x, y;
};

struct conn
{
    int t1, t2;
};

int n, m;
vector<unordered_set<int>> groups;

void mergeconns(conn conns[])
{
    int i, j;
    bool fd;
    for (j = 0; j < m; j++)
    {
        fd = false;
        for (i = 0; i < groups.size(); i++)
        {
            if (groups[i].find(conns[j].t2) != groups[i].end())
            {
                groups[i].insert(conns[j].t1);
                fd = true;
            }
            if (groups[i].find(conns[j].t1) != groups[i].end())
            {
                groups[i].insert(conns[j].t2);
                fd = true;
            }
        }
        if (!fd)
        {
            unordered_set<int> newset;
            newset.insert(conns[j].t1);
            newset.insert(conns[j].t2);
            groups.push_back(newset);
        }
    }
}

int main()
{
    int i;
    cin >> n >> m;
    unit units[n];
    conn conns[m];
    for (i = 0; i < n; i++)
    {
        cin >> units[i].x >> units[i].y;
        units[i].num = i + 1;
    }
    for (i = 0; i < m; i++)
    {
        cin >> conns[i].t1 >> conns[i].t2;
    }
    unordered_set<int> newset;
    newset.insert(conns[0].t1);
    newset.insert(conns[0].t2);
    groups.push_back(newset);
    mergeconns(conns);
    int mnX, mnY, mxX, mxY, mnperim = MAX_INT;
    for (i = 0; i < groups.size(); i++)
    {
        mnX = MAX_INT;
        mnY = MAX_INT;
        mxX = -1;
        mxY = -1;
        for (auto j = groups[i].begin(); j != groups[i].end(); j++)
        {
            if (units[*j - 1].x < mnX)
            {
                mnX = units[*j - 1].x;
            }
            if (units[*j - 1].y < mnY)
            {
                mnY = units[*j - 1].y;
            }
            if (units[*j - 1].x > mxX)
            {
                mxX = units[*j - 1].x;
            }
            if (units[*j - 1].y > mxY)
            {
                mxY = units[*j - 1].y;
            }
        }
        mnperim = min(mnperim, 2 * (mxX - mnX + mxY - mnY));
    }
    cout << mnperim;
    system("pause");
    return 0;
}