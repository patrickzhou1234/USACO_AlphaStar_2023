#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> b;
    unordered_set<int> b_set;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
        b_set.insert(tmp);
    }
    
    vector<int> a;
    for (int i = 1; i <= 2 * n; i++) {
        if (!b_set.count(i)) {
            a.push_back(i);
        }
    }
    
    int ct = 0;
    int a_index = 0;
    for (int i = 0; i < n; i++) {
        while (a_index < n && a[a_index] <= b[i]) {
            a_index++;
        }
        if (a_index < n) {
            ct++;
            a_index++;
        }
    }
    
    cout << ct;
    return 0;
}
