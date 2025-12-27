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

bool ok(vec<pair<int,int>> &v, int k) {
    int n = v.size();
    int l = 0, r = 0;

    // can go from pos-k to pos+k
    // should be in v[i] l and r
    loop(i,0,n) {
        // expand segment
        l -= k;
        r += k;
        // can be here
        l = max(v[i].F, l);
        r = min(v[i].S, r);
        if (!(l<=r)) return false;
        // if (i==n-1) return true;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vec<pair<int,int>> segs(n);
    loop(i,0,n) cin >> segs[i].F >> segs[i].S;

    int l = 0, r = 1;
    if (ok(segs,l)) {
        cout << l << "\n";
        return;
    }
    while (!ok(segs,r)) r <<= 1;
    while (r-l>1) {
        int m = (r-l)/2+l;
        // FFFFFFVVVVVV
        if (ok(segs,m)) r = m;
        else l = m;
    }

    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
