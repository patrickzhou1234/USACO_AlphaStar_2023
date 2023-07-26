#include <bits/stdc++.h>
using namespace std;

void generate_combinations(vector<int> &num_set, int N, int idx = 0, string combo = "")
{
    if (combo.size() == N)
    {
        cout << combo << endl;
        return;
    }
    if (idx >= num_set.size())
        return;

    generate_combinations(num_set, N, idx + 1, combo + to_string(num_set[idx]));

    generate_combinations(num_set, N, idx + 1, combo);
}

int main()
{
    int M;
    cin >> M;

    vector<int> num_set(M);
    for (int i = 0; i < M; i++)
    {
        cin >> num_set[i];
    }

    int N;
    cin >> N;

    generate_combinations(num_set, N);

    return 0;
}
