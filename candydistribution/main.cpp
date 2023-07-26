// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int n, ct = 0;
/*
bool isVal(int i, int candy[]) {
    for ()
}
*/

int main()
{
    int k, i, a, b;
    char type;
    cin >> n >> k;
    int adjMatrix[n + 1][n + 1] = {0};
    int candies[n + 1] = {0};
    for (i = 0; i < k; i++)
    {
        cin >> type >> a >> b;
        if (type == 'S')
        {
            adjMatrix[a][b] = adjMatrix[b][a] = 1;
        }
        else
        {
            adjMatrix[a][b] = adjMatrix[b][a] = -1;
        }
    }
    // assignCandies(0, adjMatrix, candies);
    cout << ct << endl;
    system("pause");
    return 0;
}