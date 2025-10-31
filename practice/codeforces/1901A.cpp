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
    int n, x;
    cin >> n >> x;

    vec<int> v(n);
    loop(i,0,n) cin >> v[i];

    int Md = v[0];
    loop(i,1,n) Md = max(Md, v[i]-v[i-1]);

    Md = max(Md, 2*(x-v[n-1]));

    cout << Md << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
