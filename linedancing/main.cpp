// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441402&cmid=79057
#include <iostream>
#include <deque>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, ct = 1, i, k, j;
    cin >> n;
    deque<int> ln;
    char ad, lr;
    for (i = 0; i < n; i++)
    {
        cin >> ad >> lr;
        if (ad == 'A')
        {
            if (lr == 'L')
            {
                ln.push_front(ct);
            }
            else
            {
                ln.push_back(ct);
            }
            ct++;
        }
        else
        {
            cin >> k;
            if (lr == 'L')
            {
                for (j = 0; j < k; j++)
                {
                    ln.pop_front();
                }
            }
            else
            {
                for (j = 0; j < k; j++)
                {
                    ln.pop_back();
                }
            }
        }
    }
    for (i = 0; i < ln.size(); i++)
    {
        cout << ln[i] << "\n";
    }
    return 0;
}