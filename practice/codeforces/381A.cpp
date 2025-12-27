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

    vec<int> v(n);
    loop(i,0,n) cin >> v[i];

    int s=0, d=0;
    int i=0, j=n-1;

    bool sTurn = true;
    while (i<=j) {
        int amt = max(v[i], v[j]);
        if (amt==v[i]) i++;
        else j--;

        if (sTurn) s += amt;
        else d += amt;
        sTurn = !sTurn;
    }

    cout << s << " " << d << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
