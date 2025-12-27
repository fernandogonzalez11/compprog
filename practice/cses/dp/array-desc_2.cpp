#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
// #define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

const int MOD = 1e9+7;
using pii = pair<int,int>;

void solve() {
    int n,m;
	cin>>n>>m;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	// (i, chosen num)
	// include 0 and m+1 for convenience
	vec<vec<int>> dp(n, vec<int>(m+2,0));
	if (v[0]>0) dp[0][v[0]] = 1;
	else loop(i,1,m+1) dp[0][i] = 1;

	loop(i,1,n) {
		if (v[i]>0) {
			for (auto k : {v[i]-1,v[i],v[i]+1})
				dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][k]) % MOD;
		} else {
			loop(x,1,m+1) {
				for (auto k : {x-1,x,x+1})
					dp[i][x] = (dp[i][x] + dp[i-1][k]) % MOD;
			}
		}
	}

	int amt = 0;
	loop(i,1,m+1) amt = (amt+dp[n-1][i])%MOD;

	cout << amt << "\n";

	// loop(i,0,n) {
	// 	vec<int> vv = dp[i];
	// 	printarr(vv);
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
