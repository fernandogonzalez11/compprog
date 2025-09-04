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
    int n, x;
	cin >> n >> x;
	vec<int> c;
	c.resize(n);
	loop(i,0,n) cin >> c[i];

	// dp[amt]
	// sol: dp[x]
	// dp[amt] = for each coin that we can put min(dp[amt], dp[amt - c])
	int dp[x+1];
	// base case
	dp[0] = 0;
	loop(amt,1,x+1) {
		dp[amt] = INF;
		loop(i,0,n) {
			if (amt >= c[i])
				dp[amt] = min(dp[amt], 1 + dp[amt - c[i]]);
		}
	}

	cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
