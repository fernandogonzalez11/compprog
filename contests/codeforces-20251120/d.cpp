#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i; // pos[x] is position of x in p
    }
    
    vector<int> min_prefix(n+1, n), max_suffix(n+2, -1);
    for (int i = 1; i <= n; i++) {
        min_prefix[i] = min(min_prefix[i-1], pos[i]);
    }
    for (int i = n; i >= 1; i--) {
        max_suffix[i] = max(max_suffix[i+1], pos[i]);
    }
    
    for (int i = 1; i < n; i++) {
        if (min_prefix[i] > max_suffix[i+1]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}