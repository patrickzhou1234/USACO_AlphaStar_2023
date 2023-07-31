#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int partition(int start, int end)
{

    int pivot = arr[end], i;
    int boundary = start;
    for (i = 0; i)
        for (i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    cout << "\n";
    return;
}

void quickSort(int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(start, end);

    // Sorting the left part
    quickSort(start, p - 1);

    // Sorting the right part
    quickSort(p + 1, end);
}

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    quickSort(0, n - 1);
    return 0;
}