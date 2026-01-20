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
    cin>>n;
    vec<int> v(n), uniqueamt(n);
    loop(i,0,n) cin>>v[i];

    {
        set<int> s;
        loop(i,0,n) {
            s.insert(v[i]);
            uniqueamt[i] = s.size();
        }
    }

    int amt = 0;

    {
        set<int> s;
        int ch = n-1;
        for (int i = n-1; i >= 0; i--) {
            s.insert(v[i]);
            if (s.size() == uniqueamt[ch]) {
                amt++;
                ch = i-1;
                s.clear();
            }
        }
    }

    cout << amt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}