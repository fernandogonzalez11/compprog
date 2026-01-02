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

const int MOD = 1e9+7;
const int N = 1e6;

int maxi = 2;
array<array<int, 2>, N+1> dp;

void solve() {
    int n;
    cin>>n;

    // n, split/joint
    dp[1][0] = dp[1][1] = 1;
    for (int i = maxi; i <= n; i++) {
        int both = (dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][0] = (both + 3 * dp[i-1][0]) % MOD;
        dp[i][1] = (both + dp[i-1][1]) % MOD;
    }

    int res = (dp[n][0]+dp[n][1]) % MOD;
    cout << res << "\n";

    maxi = max(maxi, n);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
