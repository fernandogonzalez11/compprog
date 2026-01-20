#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
    for (auto x : a) cout << x << " "; \
    cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
    int a,b;
    cin>>a>>b;

    // width, height = moves
    int dp[a+1][b+1];

    loop(i,1,a+1) {
        dp[i][1] = i-1;
        dp[i][0] = -1;
    }
    loop(i,1,b+1) {
        dp[1][i] = i-1;
        dp[0][i] = -1;
    }

    loop(i,1,min(a,b)+1) {
        dp[i][i] = 0;
    }

    loop(i,2,a+1) {
        loop(j,2,b+1) {
            if (i==j) continue;

            // test: i=2, j=3, will check:
            // dp[1][3] + dp[1][3] = 2 + 2
            // dp[2][2] + dp[2][1] = 0 + 1
            
            int val = INF;
            for (int k = i-1; k >= 1; k--)
                val = min(val, 1 + dp[k][j] + dp[i-k][j]);

            for (int k = j-1; k >= 1; k--)
                val = min(val, 1 + dp[i][k] + dp[i][j-k]);

            dp[i][j] = val;
        }
    }

    cout << dp[a][b] << "\n";

    // loop(i,0,a+1) {
    //     loop(j,0,b+1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}