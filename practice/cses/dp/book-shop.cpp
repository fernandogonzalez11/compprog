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
using pii = pair<int,int>;
const int MOD = 1e9+7;

void solve() {
    int n,x;
	cin>>n>>x;

	vec<pii> books(n);
	loop(i,0,n) cin >> books[i].F;
	loop(i,0,n) cin >> books[i].S;

	// pref excluding, budget
	vec<vec<int>> dp(n+1, vec<int>(x+1));
	loop(b,0,x+1) dp[0][b] = 0;
	loop(p,1,n+1) {
		loop(b,0,x+1) {
			// leave
			int val = dp[p-1][b];
			// take
			int rest = b-books[p-1].F;
			if (rest >= 0) val = max(val, books[p-1].S + dp[p-1][rest]);
			dp[p][b] = val;
		}
	}

	cout << dp[n][x] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
