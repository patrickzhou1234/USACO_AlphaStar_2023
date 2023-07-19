// link to problem
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, res = 0, i, j;
    cin >> n;
    string city, state, target;
    string citystates[n];
    vector<int> targetvec;
    for (i = 0; i < n; i++)
    {
        cin >> city >> state;
        citystates[i] = city.substr(0, 1) + state;
    }
    sort(citystates, citystates + n);
    for (i = 0; i < n; i++)
    {
        target = citystates[i].substr(2, 3) + citystates[i].substr(0, 1);
        if (citystates[i] == target)
        {
            continue;
        }
        for (j = 0; j < target.length(); j++)
        {
            targetvec.push_back((int)target[j]);
        }
        sort(targetvec.begin(), targetvec.end());
        res += upper_bound(targetvec.begin(), targetvec.end(), stoi(target)) - lower_bound(targetvec.begin(), targetvec.end(), stoi(target));
        targetvec.clear();
    }
    cout << res / 2;
    system("pause");
    return 0;
}