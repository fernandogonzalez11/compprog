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
    int n, q;
    cin >> n >> q;

    int conf = 0;
    loop(i,0,n) {
        char c; cin >> c;
        conf |= ((c=='B') << i);
    }

    loop(i,0,q) {
        int x;
        cin >> x;

        // all A is trivial
        if (!conf) cout << x << "\n";
        else {
            // existence of at least 1 type B makes it O(log(n))
            int t = 0;
            int mI = 0;
            while (x > 0) {
                if (conf & (1LL<<mI)) x /= 2;
                else x--;

                t++;
                mI = (mI+1)%n;
            }

            cout << t << "\n";
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
