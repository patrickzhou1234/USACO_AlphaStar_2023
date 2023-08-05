#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct par
{
    int t1, t2;
};

vector<unordered_set<int>> sets;
int n, m, q, mx;

void merge(par pairs[])
{
    int i, j;
    bool fd, fd2;
    for (i = 0; i < m; i++)
    {
        fd = false;
        for (j = 0; j < sets.size(); j++)
        {
            if (sets[j].find(pairs[i].t1) != sets[j].end())
            {
                fd = true;
                sets[j].insert(pairs[i].t2);
                break;
            }
            if (sets[j].find(pairs[i].t2) != sets[j].end())
            {
                fd = true;
                sets[j].insert(pairs[i].t1);
                break;
            }
        }
        if (!fd)
        {
            unordered_set<int> temp;
            temp.insert(pairs[i].t1);
            temp.insert(pairs[i].t2);
            sets.push_back(temp);
        }
    }
}

void combinePairs(par pairs[])
{
    for (int i = 0; i < m; i++)
    {
        par p = pairs[i];
        bool found = false;
        for (unordered_set<int> group : sets)
        {
            if (group.find(p.t1) != group.end() || group.find(p.t2) != group.end())
            {
                group.insert(p.t1);
                group.insert(p.t2);
                found = true;
                break;
            }
        }

        if (!found)
        {
            unordered_set<int> newSet;
            newSet.insert(p.t1);
            newSet.insert(p.t2);
            sets.push_back(newSet);
        }
    }
}

int main()
{
    bool fd;
    int i, j;
    cin >> n >> m >> q;
    par pairs[m], queries[q];
    for (i = 0; i < m; i++)
        cin >> pairs[i].t1 >> pairs[i].t2;
    for (i = 0; i < q; i++)
        cin >> queries[i].t1 >> queries[i].t2;
    combinePairs(pairs);
    for (i = 0; i < q; i++)
    {
        fd = false;
        for (j = 0; j < sets.size(); j++)
        {
            if (sets[j].find(queries[i].t1) != sets[j].end() && sets[j].find(queries[i].t2) != sets[j].end())
            {
                cout << "Y" << endl;
                fd = true;
                break;
            }
        }
        if (!fd)
            cout << "N" << endl;
    }
    system("pause");
    return 0;
}