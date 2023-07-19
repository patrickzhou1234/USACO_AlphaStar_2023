// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441002&cmid=79058&page=1
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#define MAX_INT 2147483647
#define MOD 1000000007

long long factorial(long long n)
{
    if (n < 0)
        return (-1);
    if (n == 0)
        return (1);
    else
    {
        return (n * factorial(n - 1));
    }
}

int main()
{
    string name;
    long long n, res, i, j, ct;
    cin >> name;
    n = name.length();
    res = 0;
    for (i = 0; i < n; i++)
    {
        ct = 0;
        for (j = i + 1; j < n; j++)
        {
            if (name[j] < name[i])
            {
                ct++;
            }
        }
        res += ct * factorial(n - i - 1);
        res %= MOD;
    }
    cout << res % MOD + 1;
    return 0;
}