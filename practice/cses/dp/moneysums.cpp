#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vec<int> coins(n);
    loop(i,0,n) cin >> coins[i];

    set<int> set = {0}, set2;
    loop(i,0,n) {
        set2 = {};
        for (auto p = set.begin(); p != set.end(); p++)
            set2.insert(*p+coins[i]);

        set.merge(set2);
    }

    set.erase(0);

    cout << set.size() << "\n";
    for (auto u : set)
        cout << u << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}