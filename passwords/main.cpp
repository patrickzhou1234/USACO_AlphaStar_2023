// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=446460&cmid=80228
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

string init;
int k;

char getChar(int k, int l)
{
    if (k < init.length())
    {
        return init.at(k);
    }
    if (k < l / 2)
    {
        return getChar(k, l / 2);
    }
    if (k >= l / 2)
    {
        return getChar((k - 1) % (l / 2), l / 2);
    }
}

int main()
{
    int initialLength;
    cin >> init;
    cin >> k;
    k--;
    initialLength = init.length();
    while (initialLength <= k)
    {
        initialLength *= 2;
    }
    cout << getChar(k, initialLength);
    system("pause");
    return 0;
}