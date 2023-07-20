// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    string firstcow = "", secondcow = "";
    int n, m, i, tmpamt, j, mxln, firstcowpos = 0, secondcowpos = 0, ct = 0;
    char tmpdir;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> tmpamt >> tmpdir;
        for (j = 0; j < tmpamt; j++)
        {
            firstcow += tmpdir;
        }
    }
    for (i = 0; i < m; i++)
    {
        cin >> tmpamt >> tmpdir;
        for (j = 0; j < tmpamt; j++)
        {
            secondcow += tmpdir;
        }
    }
    mxln = max(firstcow.length(), secondcow.length());
    bool prevvis = false;
    for (i = 0; i < mxln; i++)
    {
        if (i < firstcow.length())
        {
            if (firstcow[i] == 'L')
                firstcowpos--;
            if (firstcow[i] == 'R')
                firstcowpos++;
        }
        if (i < secondcow.length())
        {
            if (secondcow[i] == 'L')
                secondcowpos--;
            if (secondcow[i] == 'R')
                secondcowpos++;
        }
        if (firstcowpos == secondcowpos)
        {
            if (!prevvis)
            {
                ct++;
            }
            prevvis = true;
        }
        else
        {
            prevvis = false;
        }
    }
    cout << ct;
    return 0;
}