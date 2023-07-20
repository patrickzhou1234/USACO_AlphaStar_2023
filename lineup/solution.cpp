// link to problem
#include <iostream>
#include <stack>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i;
    cin >> n;
    int a[n], nextGreatestEl[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        nextGreatestEl[i] = 0;
    }
    stack<int> s;
    for (i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[i] >= a[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
        {
            nextGreatestEl[i] = s.top() + 1;
        }
        s.push(i);
    }
    for (int b : nextGreatestEl)
    {
        cout << b << "\n";
    }
    system("pause");
    return 0;
}