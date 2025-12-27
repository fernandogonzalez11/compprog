#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) cout << #a << ": "; \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;

void solve() {
    int n;
    cin>>n;

    vec<int> v(n);
    loop(i,0,n) cin >> v[i];

    loop(_,0,n) {
        loop(i,1,n-1) {
            if (v[i-1]<v[i]&&v[i]>v[i+1]) swap(v[i],v[i+1]);
        }
    }

    loop(i,1,n) {
        if (v[i]<v[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

    // apparently this is possible <=> v[0] = 1 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
