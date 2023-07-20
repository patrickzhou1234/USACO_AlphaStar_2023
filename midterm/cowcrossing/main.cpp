// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=442713&cmid=78345&page=2
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int c;

struct ferryunit
{
    int time;
    int capa = c;
};

int main()
{
    int n, m, i, j, l;
    cin >> n >> m >> c;
    int times[n];
    for (i = 0; i < n; i++)
    {
        cin >> times[i];
    }
    sort(times, times + n);
    ferryunit timeferry[m];
    for (i = 0; i < m; i++)
    {
        timeferry[i].time = -1;
        timeferry[i].capa = c;
    }
    for (i = 0; i < m; i++)
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (timeferry[j].time != -1)
            {
                timeferry[j].time = times[i];
            }
        }

        for (j = 0; j < m; j++)
        {
            for (l = 0; l < n; l++)
            {
                if (times[l] < timeferry[j].time && timeferry[j].capa > 0)
                {
                    timeferry[j].capa--;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    system("pause");
    return 0;
}