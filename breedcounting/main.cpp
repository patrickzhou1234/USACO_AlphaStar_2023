// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=442935&cmid=78366&page=1
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, q, i, num, a, b;
    cin >> n >> q;
    int psum1[n + 1], psum2[n + 1], psum3[n + 1];
    psum1[0] = 0;
    psum2[0] = 0;
    psum3[0] = 0;
    for (i = 1; i <= n; i++)
    {
        psum1[i] = psum1[i - 1];
        psum2[i] = psum2[i - 1];
        psum3[i] = psum3[i - 1];
        cin >> num;
        if (num == 1)
        {
            psum1[i]++;
        }
        else if (num == 2)
        {
            psum2[i]++;
        }
        else
        {
            psum3[i]++;
        }
    }
    for (i = 0; i < q; i++)
    {
        cin >> a >> b;
        cout << psum1[b] - psum1[a - 1] << " " << psum2[b] - psum2[a - 1] << " " << psum3[b] - psum3[a - 1] << "\n";
    }
    system("pause");
    return 0;
}