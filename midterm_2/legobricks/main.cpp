// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=449140&cmid=80231
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

char mat[50][50];

void section(int x, int y, char id)
{
    if (mat[x + 1][y] == 'X')
    {
        mat[x + 1][y] = id;
        section(x + 1, y, id);
    }
    if (mat[x - 1][y] == 'X')
    {
        mat[x - 1][y] = id;
        section(x - 1, y, id);
    }
    if (mat[x][y + 1] == 'X')
    {
        mat[x][y + 1] = id;
        section(x, y + 1, id);
    }
    if (mat[x][y - 1] == 'X')
    {
        mat[x][y - 1] = id;
        section(x, y - 1, id);
    }
}

int main()
{
    int n, m, i, j, k, xpos, ypos;
    bool fd;
    cin >> n >> m;
    fd = false;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'X' && !fd)
            {
                mat[i][j] = '1';
                xpos = i, ypos = j;
                fd = true;
            }
        }
    }
    section(xpos, ypos, '1');
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] == 'X')
            {
                xpos = i, ypos = j;
                break;
            }
        }
    }
    section(xpos, ypos, '2');
    int mn = MAX_INT;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m - 1; j++)
        {
            if (mat[i][j] == '1' && mat[i][j + 1] == '.')
            {
                for (k = j + 1; k < m; k++)
                {
                    if (mat[i][k] == '2')
                    {
                        mn = min(mn, k - j - 1);
                        break;
                    }
                }
            }
        }
    }
    if (mn == MAX_INT)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (mat[j][i] == '1' && mat[j + 1][i] == '.')
                {
                    for (k = j + 1; k < n; k++)
                    {
                        if (mat[k][i] == '2')
                        {
                            mn = min(mn, k - j - 1);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << mn << endl;
    system("pause");
    return 0;
}