// link to problem
#include <iostream>
#include <cmath>
#include <ctype.h>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int i, j, tmpLn, mxLn = -MAX_INT, rptr, lptr, st, nd, ct;
    string s, res;
    getline(cin, s);
    for (i = 0; i < s.length(); i++)
    {
        int ln = s.length();
        tmpLn = max(i, ln - 1 - i);
        lptr = 0, rptr = 0;
        for (j = 0; j < tmpLn; j++)
        {
            if (!isalpha(s[i - j - lptr]))
            {
                lptr++;
            }
            if (!isalpha(s[i + j + rptr]))
            {
                rptr++;
            }
            if (s[i - j - lptr] != s[i + j + rptr])
            {
                break;
            }
        }
        if (2 * j > mxLn)
        {
            mxLn = 2 * j;
            st = i - j - lptr;
            nd = i + j + rptr;
        }
    }
    res = s.substr(st, nd);
    for (i = 0; i < res.length(); i++)
    {
        if (!isalpha(res[i]))
        {
            res.erase(i, 1);
            i--;
        }
        else
        {
            break;
        }
    }
    for (i = res.length() - 1; i >= 0; i--)
    {
        if (!isalpha(res[i]))
        {
            res.erase(i, 1);
        }
        else
        {
            break;
        }
    }
    ct = 0;
    for (i = 0; i < res.length(); i++)
    {
        if (isalpha(res[i]))
        {
            ct++;
        }
    }
    cout << ct << "\n"
         << res;
    system("pause");
    return 0;
}