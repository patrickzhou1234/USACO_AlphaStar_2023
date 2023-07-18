// https://lms.alphastar.academy/mod/quiz/attempt.php?attempt=441274&cmid=78329&page=1
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, num, j;
    char c;
    cin >> n;
    vector<int> registers[n + 1];
    queue<int> line;
    while (cin >> c >> num)
    {
        // cin >> c >> num;
        if (c == 'C')
        {
            line.push(num);
        }
        else
        {
            registers[num].push_back(line.front());
            line.pop();
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << registers[i].size() << " ";
        for (j = 0; j < registers[i].size(); j++)
        {
            cout << registers[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}