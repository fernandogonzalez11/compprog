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

bool ok(vec<int> &a, vec<int> &b, int remove) {
    int n = a.size();

    for (int i = 0; i < n-remove; i++) {
        int aa = a[i], bb = b[i+remove];
        if (aa>=bb) return false;
    }

    return true;
}

void solve() {
    int n,m;
    cin>>n>>m;
    
    vec<int> a(n),b(n);
    a[0]=1;
    loop(i,1,n) cin >> a[i];
    loop(i,0,n) cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // printarr(a);
    // printarr(b);

    // first attempt: deque-like
    // remove from right of a, from left of b
    // binary search this
    int l = 0, r = n;
    while (r-l>1) {
        int m = (r-l)/2+l;
        if (ok(a,b,m)) r = m;
        else l = m;
    }

    if (ok(a,b,l)) cout << l << "\n";
    else cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
