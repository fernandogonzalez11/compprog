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

int c[] = {1,3,6,10,15};

const int N = 500;
int dp[N];

void precalc() {
	dp[0] = 0;
	for (int i = 1; i < N; i++) {
		dp[i] = INF;
		for (int cc : c)
			if (i-cc >= 0)
				dp[i] = min(dp[i], dp[i-cc]+1);
	}
}

void solve(int n) {
	if (n <= 100) {
		cout << dp[n] << "\n";
	} else {
		int u = (n-100)/15 + ((n-100)%15 > 0);
		n -= 15*u;

		cout << u + dp[n] << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// cout << INF;
	precalc();

	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		solve(n);
	}

	return 0;
}
