// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int n, m, numHappyCows = 0;
vector<int> firstChoices, secondChoices, res, cowThatTook;

void assign(int cow, int donut)
{
    int nxt, i, ct = 0;
    if (cowThatTook[donut] == -1)
    {
        cowThatTook[donut] = cow;
        for (i = 0; i < cowThatTook.size(); i++)
            if (cowThatTook[i] == -1)
                ct++;
        res.push_back(ct);
        return;
    }
    nxt = cowThatTook[donut];
    cowThatTook[donut] = cow;
    if (donut == firstChoices[nxt])
        assign(nxt, secondChoices[nxt]);
    else
        return;
}

int main()
{
    int i, tmpF, tmpS, ct = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> tmpF >> tmpS;
        firstChoices.push_back(tmpF);
        secondChoices.push_back(tmpS);
    }
    for (i = 0; i < m; i++)
        cowThatTook.push_back(-1);
    for (i = n - 1; i >= 0; i--)
    {
        assign(i, firstChoices[i]);
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}