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

const int BITS = 32;

// O(32)
bool ok(vec<vec<int>> &amtones, int k, int l, int r) {
    int tot = 0;
    loop(i,0,BITS) {
        int amt = amtones[i][r];
        if (l) amt -= amtones[i][l-1];
        tot |= ((amt == r-l+1) << i);
    }

    // cout << l << "-" << r<<"t"<<tot<<" ";

    return tot >= k;
}

void solve() {
    int n;
    cin >> n;
    vec<int> a(n);
    loop(i,0,n) cin >> a[i];

    // if a bit in f(l,r) is 1
    // this means all numbers in [l,r] have that bit set
    // make a matrix per bit

    vec<vec<int>> amtones(BITS, vec<int>(n));
    loop(i,0,BITS)
        amtones[i][0] = (a[0]&(1<<i))>0;

    loop(i,0,BITS)
        loop(j,1,n)
            amtones[i][j] = amtones[i][j-1] + ((a[j]&(1<<i))>0);

    // loop(i,0,BITS) {
    //     vec<int> vvv = amtones[i];
    //     cout << i << " ";
    //     printarr(vvv);
    // }

    int q;
    cin >> q;
    
    loop(_,0,q) {
        int l,k;
        cin>>l>>k;
        l--;

        int rl=l, rr=n-1;
        if (!ok(amtones, k, l, l)) cout << "-1 ";
        else if (ok(amtones, k, l, rr)) cout << rr+1 << " ";
        else {
            while (rr-rl>1) {
                int m = (rr-rl)/2+rl;
                // VVVVVVVFFFFFFF
                if (ok(amtones, k, l, m)) rl=m;
                else rr=m;
            }

            cout << rl+1 << " ";
        }
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
