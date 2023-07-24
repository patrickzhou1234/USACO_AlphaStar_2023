// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    system("pause");
    return 0;
}