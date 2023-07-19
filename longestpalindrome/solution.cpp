// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=440877&cmid=78324&scrollpos=657
#include <iostream>
#include <ctype.h>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int l, r, prevL, prevR, len, n, i, lc, rc, resLen = 0, resBegin, resEnd;
    string s, line;
    while (getline(cin, line))
    {
        s += line;
    }
    n = s.length();
    for (i = 0; i < n; i++)
    {
        l = i, r = i, prevL = i, prevR = i, len = 0;
        while (0 <= l && r < n)
        {
            lc = tolower(s[l]), rc = tolower(s[r]);
            if (!isalpha(lc))
            {
                l--;
            }
            else if (!isalpha(rc))
            {
                r++;
            }
            else if (lc == rc)
            {
                if (l == r)
                {
                    len++;
                }
                else
                {
                    len += 2;
                }
                prevL = l;
                prevR = r;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        if (len > resLen)
        {
            resLen = len;
            resBegin = prevL;
            resEnd = prevR;
        }
        else if (len == resLen && prevL < resBegin)
        {
            resBegin = prevL;
            resEnd = prevR;
        }
    }
    cout << resLen << "\n"
         << s.substr(resBegin, resEnd);
    system("pause");
    return 0;
}