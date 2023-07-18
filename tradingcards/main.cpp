// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=439991&cmid=78318
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, b, i, res, capa, cnt, cur, j, mxCards;
    cin >> n >> b;
    int cards[n];
    for (i = 0; i < n; i++)
    {
        cin >> cards[i];
    }
    mxCards = 0;
    for (i = 0; i < n; i++)
    {
        mxCards = max(cards[i], mxCards);
    }
    res = 0;
    // sort(cards, cards + n);
    for (capa = 1; capa <= mxCards; capa++)
    {
        int boxes[capa + 1];
        for (i = 0; i < n; i++)
        {
            boxes[capa] = cards[i] / capa;
            boxes[cards[i] % capa]++;
        }
        i = capa;
        cnt = 0;
        cur = 0;
        while (cnt < b)
        {
            for (j = 0; j < boxes[i]; j++)
            {
                if (cnt >= b)
                {
                    break;
                }
                if (cnt >= b / 2)
                {
                    cur += i;
                }
                cnt++;
            }
        }
        res += cur;
    }
    cout << res;
    system("pause");
    return 0;
}