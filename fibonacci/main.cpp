// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n - 1);
    system("pause");
    return 0;
}