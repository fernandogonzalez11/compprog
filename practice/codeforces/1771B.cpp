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
    int n,m;
    cin >> n>>m;
    vec<int> upto(n,n);
    loop(i,0,m) {
        int a,b;
        cin>>a>>b;

        if (a>b) swap(a,b);
        upto[a-1] = min(upto[a-1], b-1);
    }

    // printarr(upto);

    for (int i=n-2; i >= 0; i--) {
        upto[i] = min(upto[i],upto[i+1]);
    }

    int s=0;
    loop(i,0,n) s += upto[i]-i;

    cout << s << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
