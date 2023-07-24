// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n;

bool isPrime(int x)
{
    int i;
    if (x <= 1)
    {
        return false;
    }
    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void gen(int i, int acc)
{
    int j;
    if (i == n)
        cout << acc << "\n";
    for (j = 0; j <= 9; j++)
        if (isPrime(acc * 10 + j))
            gen(i + 1, acc * 10 + j);
}

int main()
{
    cin >> n;
    gen(0, 0);
    system("pause");
    return 0;
}