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

int MOD = 1e9+7;

using namespace std;

void solve() {
	int n;
	cin >> n;

	if (n <= 6) {
		cout << (1LL << (n-1)) << "\n";
		return;
	}
	
	int dp[n+1];
	loop(i,1,6+1) dp[i] = (1LL << (i-1));

	loop(i,7,n+1) {
		int s = 0;
		loop(j,i-6,i) {
			s += dp[j];
			s %= MOD;
			// cout << s << "\n";	
		}
		dp[i] = s;
	}
	cout << dp[n] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
