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

const int MOD = 1000000007;

void solve() {
    int n, k;
	cin >> n >> k;

	// cout << n << k << "\n";

	int dp[n];

	loop(i,1,n+1) dp[i-1] = 1;
	loop(e,1,k) {
		int dp2[n];
		loop(i,1,n+1) {
			int cnt = 0;
			for (int c = i; c <= n; c += i) {
				cnt += dp[c-1];
				cnt %= MOD;
			}
			dp2[i-1] = cnt;
		}

		loop(i,0,n) dp[i] = dp2[i];
	}

	// loop(i,0,k) {
	// 	vec<int> p(dp[i], dp[i]+n);
	// 	printarr(p);
	// }

	int finalC = 0;
	loop(i,0,n) {
		finalC += dp[i];
		finalC %= MOD;
	}

	cout << finalC << "\n";
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
