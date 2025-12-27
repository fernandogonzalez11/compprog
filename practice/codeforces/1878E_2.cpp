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

struct segtree {
    static const int N = 1e5;  // limit for array size
    int n;  // array size
    int t[2 * N];

    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] & t[i<<1|1];
    }

    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] & t[p^1];
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = ~0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res &= t[l++];
            if (r&1) res &= t[--r];
        }
        return res;
    }
};


void solve() {
    int n;
    cin >> n;
    vec<int> a(n);
    loop(i,0,n) cin >> a[i];

    segtree seg;
    seg.n = n;
    loop(i,0,n) seg.t[n+i] = a[i];
    seg.build();

    int q;
    cin >> q;

    // (p and q) or p = p

    // O(q * log^2 n)
    loop(_,0,q) {
        int l,k;
        cin >> l >> k;
        l--;

        int rl = l, rr = n-1;
        // cout << "d:" << seg.query(rl, rr+1) << "\n";

        if (a[rl]<k) {
            cout << "-1 ";
            continue;
        } else if (seg.query(rl, rr+1)>=k) {
            cout << rr+1 << " ";
            continue;
        }

        // cout << seg.query(rl,rl+2) << "#";

        while (rr-rl>1) {
            int m = (rr-rl)/2+rl;
            // VVVVVVVFFFFFFF
            if (seg.query(l,m+1)>=k) rl = m;
            else rr = m;
        }
        cout << rl+1 << " ";
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
