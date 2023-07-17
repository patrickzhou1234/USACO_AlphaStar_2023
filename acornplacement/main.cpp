// link to problem
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, q, i, j, ct, a, b, tmp;
    cin >> n >> q;
    vector<int> locations;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        locations.push_back(tmp);
    }
    sort(locations.begin(), locations.end());
    for (i = 0; i < q; i++)
    {
        cin >> a >> b;
        vector<int>::iterator ubnd, lbnd;
        ubnd = upper_bound(locations.begin(), locations.end(), b);
        lbnd = lower_bound(locations.begin(), locations.end(), a);
        cout << ubnd - lbnd << "\n";
    }
    system("pause");
    return 0;
}