#include <algorithm>
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

using pii = pair<int,int>;

void solve() {
    int n;
	cin>>n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	int M = *max_element(v.begin(),v.end());

	vec<vec<int>> appearances(M+1);
	// vec<int> freq(M+1,0), curstart(M+1,0);
	vec<int> starts(n,-1);
	loop(i,0,n) {
		appearances[v[i]].push_back(i);
		int sz = appearances[v[i]].size();
		if (sz>=v[i]) {
			starts[i] = appearances[v[i]][sz-1-v[i]+1];
		}

		// if (v[i]==1) {
		// 	starts[i] = i;
		// 	continue;
		// }

		// int r = ++freq[v[i]] % v[i];
		// if (r == 1) curstart[v[i]] = i;
		// else if (r == 0) starts[i] = curstart[v[i]];
	}

	// printarr(starts);

	vec<int> dp(n+2);
	// -1
	dp[0] = 0;
	loop(i,0,n) {
		dp[i+1] = dp[i];
		if (starts[i]>=0) dp[i+1] = max(dp[i+1], v[i]+dp[starts[i]-1+1]);
	}
	cout << dp[n] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
