// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441274&cmid=78329&scrollpos=1895
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, ct, i;
    cin >> n;
    string op;
    stack<int> s;
    ct = 1;
    for (i = 0; i < n; i++)
    {
        cin >> op;
        if (op == "ADD")
        {
            s.push(ct);
            ct++;
        }
        else
        {
            s.pop();
        }
    }
    cout << s.size() << "\n";
    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    for (i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << "\n";
    }
    system("pause");
    return 0;
}