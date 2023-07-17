// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=439829&cmid=78314
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_INT 2147483647

struct Seat
{
    int row, col, dist;
};

bool Comp(Seat seat1, Seat seat2)
{
    if (seat1.dist != seat2.dist)
    {
        return seat1.dist < seat2.dist;
    }
    if (seat1.row != seat2.row)
    {
        return seat1.row > seat2.row;
    }
    return seat1.col < seat2.col;
}

int main()
{
    int w, r, seat1Row, seat1Col, i, j, rtmp, wtmp, dr, dc;
    cin >> w >> r;
    Seat seats[r * w];
    seat1Row = r - 1;
    seat1Col = (w + 1) / 2 - 1;
    i = 0;
    for (rtmp = 0; rtmp < r; rtmp++)
    {
        for (wtmp = 0; wtmp < w; wtmp++)
        {
            seats[i].row = rtmp;
            seats[i].col = wtmp;
            dr = seat1Row - rtmp;
            dc = seat1Col - wtmp;
            seats[i].dist = dr * dr + dc * dc;
            i++;
        }
    }
    sort(seats, seats + w * r, Comp);

    int res[r][w];
    for (i = 0; i < r * w; i++)
    {
        res[seats[i].row][seats[i].col] = i + 1;
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < w; j++)
        {
            cout << res[i][j];
            if (j != w - 1)
            {
                cout << " ";
            }
        }
        if (i != r - 1)
        {
            cout << "\n";
        }
    }
    return 0;
}