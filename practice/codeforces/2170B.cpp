#include <algorithm>
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

int calc(int sum, int l, int r) {
    return 1 + (sum - (r-l+1));
}

void solve() {
    int n;
    cin >> n;
    vec<int> v(n);
    loop(i,0,n) cin >> v[i];
    sort(v.begin(),v.end());

    int sum = accumulate(v.begin(),v.end(),0LL);

    int l = upper_bound(v.begin(),v.end(),0LL)-v.begin();
    if (l==n) { cout << "0\n"; return; }

    for (int r = n-1; r >= l; r--) {
        int upp = calc(sum,l,r);
        if (upp >= n) {
            cout << r-l+1 << "\n";
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
