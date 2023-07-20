#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canArrangeCows(int n, int m, int c, vector<int> &wakeUpTimes, int x)
{
    int ferryIndex = 0;
    int cowIndex = 0;
    while (ferryIndex < m && cowIndex < n)
    {
        int departureTime = wakeUpTimes[cowIndex] + x;
        int cowsOnFerry = 0;

        while (cowIndex < n && wakeUpTimes[cowIndex] <= departureTime && cowsOnFerry < c)
        {
            cowIndex++;
            cowsOnFerry++;
        }

        ferryIndex++;
    }
    return cowIndex == n;
}

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> wakeUpTimes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wakeUpTimes[i];
    }

    sort(wakeUpTimes.begin(), wakeUpTimes.end());

    int low = 0;
    int high = 1e9;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canArrangeCows(n, m, c, wakeUpTimes, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
