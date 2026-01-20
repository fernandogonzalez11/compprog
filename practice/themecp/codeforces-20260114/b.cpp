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
	int n;
	cin>>n;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	vec<int> maxpref(n), sumsuf(n+1);
	maxpref[0] = v[0];
	loop(i,1,n) maxpref[i] = max(maxpref[i-1],v[i]);
	sumsuf[n] = 0;
	for (int i = n-1; i >= 0; i--) sumsuf[i] = sumsuf[i+1] + v[i];

	vec<int> res(n+1);
	for (int k = 1; k <= n-1; k++) {
		res[k] = max(
			sumsuf[n-k],
			sumsuf[n-k+1] + maxpref[n-k-1]
		);
	}
	res[n] = sumsuf[0];

	loop(i,1,n+1) cout << res[i] << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
