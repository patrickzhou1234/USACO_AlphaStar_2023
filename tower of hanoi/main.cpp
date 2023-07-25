#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, randi, stepct = MAX_INT, tmp;
    cin >> n;
    vector<int> a, b, c;
    string s = "";
    for (i = n - 1; i >= 0; i--)
    {
        a.push_back(i);
    }
    srand(time(NULL));
    while (stepct != 7)
    {
        tmp = 0;
        while (c.size() != n)
        {
            randi = rand() % (6);
            if (a.size() > 0 && ((b.size() > 0 && b.back() < a.back()) || b.size() == 0) && randi == 0)
            {
                s += "1 --> 2\n";
                tmp++;
                b.push_back(a.back());
                a.pop_back();
            }
            if (a.size() > 0 && ((c.size() > 0 && c.back() < a.back()) || c.size() == 0) && randi == 1)
            {
                s += "1 --> 3\n";
                tmp++;
                c.push_back(a.back());
                a.pop_back();
            }
            if (b.size() > 0 && ((c.size() > 0 && c.back() < b.back()) || c.size() == 0) && randi == 2)
            {
                s += "3 --> 2\n";
                tmp++;
                c.push_back(b.back());
                b.pop_back();
            }
            if (b.size() > 0 && ((a.size() > 0 && a.back() < b.back()) || a.size() == 0) && randi == 3)
            {
                s += "1 --> 2\n";
                tmp++;
                a.push_back(b.back());
                b.pop_back();
            }
            if (c.size() > 0 && ((b.size() > 0 && b.back() < c.back()) || c.size() == 0) && randi == 4)
            {
                s += "2 --> 3\n";
                tmp++;
                b.push_back(c.back());
                c.pop_back();
            }
            if (c.size() > 0 && ((a.size() > 0 && a.back() < c.back()) || a.size() == 0) && randi == 5)
            {
                s += "1 --> 3\n";
                tmp++;
                a.push_back(c.back());
                c.pop_back();
            }
        }
        b.clear();
        c.clear();
        a.clear();
        for (i = n - 1; i >= 0; i--)
        {
            a.push_back(i);
        }
        stepct = min(stepct, tmp);
    }
    cout << s;
    return 0;
}