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
    
    // lose: cur > last

    int l = INF, r = INF, p = 0;
    loop(i,0,n) {
        int x;
        cin >> x;
        
        if (l==INF) l = x;
        // potential loss
        else if (x > l) {
            if (x <= r) r = x;
            else {
                // lose both: choose lower one
                l < r ? l = x : r = x;
                p++;
            }
        // win
        } else {
            if (x <= r) {
                // win both: choose lower one
                l < r ? l = x : r = x;
            } else l = x;
        }
    }

    cout << p << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
