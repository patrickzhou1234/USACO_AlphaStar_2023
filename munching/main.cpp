// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

char grid[100][100];
vector<string> paths;

void walk(int x, int y, string path)
{
    if (grid[x][y] == 'B')
    {
        paths.push_back(path);
        return;
    }
    grid[x][y] = 'X';
    if (grid[x][y + 1] == '.')
    {
        walk(x, y + 1, path + 'R');
    }
    if (grid[x][y - 1] == '.')
    {
        walk(x, y - 1, path + 'L');
    }
    if (grid[x + 1][y] == '.')
    {
        walk(x + 1, y, path + 'D');
    }
    if (grid[x - 1][y] == '.')
    {
        walk(x - 1, y, path + 'U');
    }
}

int main()
{
    int r, c, i, j, sX, sY, eX, eY;
    cin >> r >> c;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'C')
            {
                sX = i;
                sY = j;
            }
            if (grid[i][j] == 'B')
            {
                eX = i;
                eY = j;
            }
        }
    walk(sX, sY, "");
    for (string s : paths)
    {
        cout << s << endl;
    }
    system("pause");
    return 0;
}