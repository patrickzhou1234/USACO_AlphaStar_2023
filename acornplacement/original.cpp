// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=440264&cmid=79054
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct query
{
    int a, b;
};

int main()
{
    int n, q, i, j, ct, a, b;
    cin >> n >> q;
    int locations[n];
    query queries[q];
    for (i = 0; i < n; i++)
    {
        cin >> locations[i];
    }
    sort(locations, locations + n);
    for (i = 0; i < q; i++)
    {
        ct = 0;
        cin >> queries[i].a >> queries[i].b;
        for (j = 0; j < n; j++)
        {
            if (queries[i].a >= j)
            {
                a = j;
                break;
            }
        }
        for (j = n - 1; j >= 0; j--)
        {
            if (queries[i].b <= j)
            {
                b = j;
                break;
            }
        }
        ct = b - a - 1;
        cout << ct << "\n";
    }
    system("pause");
    return 0;
}