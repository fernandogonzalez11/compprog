#include <bits/stdc++.h>
#include <cassert>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) /*cout << #a << ": ";*/ \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
    int n,m;
    cin>>n>>m;
    vec<int> a(n), b(m);
    loop(i,0,n) cin>>a[i];
    loop(i,0,m) cin>>b[i];

    // pref excl a, pref excl b
    int dp[n+1][m+1];
    char choice[n+1][m+1];
    loop(i,0,n+1) choice[i][0] = dp[i][0] = 0;
    loop(i,0,m+1) choice[0][i] = dp[0][i] = 0;

    loop(i,1,n+1) {
        loop(j,1,m+1) {
            if (a[i-1]==b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                choice[i][j] = 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                choice[i][j] = (dp[i][j]==dp[i-1][j]) ? 2 : 3;
            }
        }
    }

    cout << dp[n][m] << "\n";

    vec<int> res;
    int p1 = n, p2 = m, val;
    while ((val = choice[p1][p2])) {
        if (val == 1) {
            assert(a[p1-1] == b[p2-1]);
            res.push_back(a[p1-1]);
            p1--;
            p2--;
        } else if (val == 2) {
            p1--;
        } else if (val == 3) {
            p2--;
        }
    }

    reverse(all(res));
    printarr(res);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}