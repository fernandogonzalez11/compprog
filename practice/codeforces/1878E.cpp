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
    cin >> n;
    vec<int> a(n);
    loop(i,0,n) cin >> a[i];

    vec<int> andsuf(n), orpref(n+1);
    andsuf[n-1]=a[n-1];
    for (int i = n-2; i; i--) andsuf[i] = andsuf[i+1] & a[i];
    orpref[0]=a[0];
    orpref[n]=0;
    for (int i = 1; i < n; i++) orpref[i] = orpref[i-1] | a[i];

    int q;
    cin >> q;

    // (p and q) or p = p
    loop(_,0,q) {
        int l,k;
        cin >> l >> k;
        l--;

        int lton = andsuf[l];

        auto ok = [&](int r) {
            return (lton | orpref[r+1]) >= k;
        };

        // VVVVVVFFFFF
        int rl = l, rr = n-1;
        if (!ok(rl)) {
            cout << "-1\n";
            return;
        }
        while (rr-rl>1) {
            int m = (rr-rl)/2+rl;
            if (ok(m)) rl = m;
            else rr = m;
        }
        cout << (ok(rr) ? rr+1 : rl+1) << " ";
    }

    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
