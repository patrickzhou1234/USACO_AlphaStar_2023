#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

#define MAX_INT 2147483647
#define MAX_LONGLONG 9223372036854775807

struct dog
{
    int pos, breed;
};

bool comp(dog a, dog b)
{
    return a.pos < b.pos;
}

int main()
{
    unordered_set<int> breeds, breeds2;
    long long n, i, j, m, mn = MAX_LONGLONG, enddog, stdog;
    cin >> n;
    dog dogs[n];
    for (i = 0; i < n; i++)
    {
        cin >> dogs[i].pos >> dogs[i].breed;
        if (breeds.find(dogs[i].breed) == breeds.end())
            breeds.insert(dogs[i].breed);
    }
    sort(dogs, dogs + n, comp);
    for (i = breeds.size(); i <= n; i++)
    {
        for (j = 0; j < n - i + 1; j++)
        {
            breeds2.clear();
            for (m = j; m < j + i; m++)
            {
                if (breeds2.find(dogs[m].breed) == breeds2.end())
                    breeds2.insert(dogs[m].breed);
            }
            if (breeds2.size() == breeds.size())
            {
                enddog = dogs[j + i - 1].pos;
                stdog = dogs[j].pos;
                mn = min(mn, enddog - stdog);
            }
        }
    }
    cout << mn;
    system("pause");
    return 0;
}