#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647
#define MARGIN 1000
#define SIZE 3000

struct coord
{
    int x, y;
};

vector<coord> adjacent(int r, int c)
{
    vector<coord> res;
    int i;
    for (i = 0; i < r; i++)
    {
        res.push_back({i, c});
    }
    for (i = 0; i < c; i++)
    {
        res.push_back({r, i});
    }
    return res;
}

bool isComfortable(int r, int c)
{
    int i, ct = 0;
    for (i = 0; i < r; i++)
    {
        if ()
    }
}

int main()
{
    int n;
    cin >> n;
    int pasture[SIZE][SIZE];
    int tCows = 0;
    system("pause");
    return 0;
}