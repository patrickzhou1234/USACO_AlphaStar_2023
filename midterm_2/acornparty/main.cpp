#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define pb push_back

vector<int> friends[1000005], groups[1000005];
int deg[1000005];
bool visited[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, G;
    cin >> N >> G;

    for (int i = 1; i <= G; i++)
    {
        int S;
        cin >> S;
        while (S--)
        {
            int f;
            cin >> f;
            groups[i].pb(f);
            friends[f].pb(i);
            deg[i]++;
        }
    }

    set<pair<int, int>> s;
    for (int g : friends[1])
    {
        s.insert({deg[g], g});
    }

    int ans = 0;
    while (!s.empty())
    {
        auto it = s.begin();
        int g = it->second;
        s.erase(it);
        if (visited[g])
            continue;
        ans += groups[g].size();
        for (int f : groups[g])
        {
            for (int g2 : friends[f])
            {
                if (!visited[g2])
                {
                    s.erase({deg[g2], g2});
                    deg[g2]--;
                    s.insert({deg[g2], g2});
                }
            }
        }
        visited[g] = true;
    }

    cout << ans << "\n";

    return 0;
}
