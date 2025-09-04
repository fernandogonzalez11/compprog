#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

int n;
string s;
vec<pair<int, int>> g;
vec<int> dp;

int amt(int i) {
	if (dp[i] != -1) return dp[i];

	char c = s[i];
	int l = g[i].F, r = g[i].S;

	// no benefit in changing a leaf
	if (l == -1 && r == -1) return 0;

	if (c == 'U') {
		// always change U (doesnt help having it) and go down on either side
		return dp[i] = min(1 + amt(l), 1 + amt(r));
	} else if (c == 'L') {
		// either change c to R, or keep current path
		return dp[i] = min(amt(l), 1 + amt(r));
	} else {
		return dp[i] = min(1 + amt(l), amt(r));
	}
}

void solve() {
    
	cin >> n;
	
	cin >> s;
	
	g.resize(n);
	dp.resize(n);
	fill(dp.begin(), dp.end(),  -1);

	loop(i,0,n) {
		int a,b;
		cin >> a >> b;
		a--; b--;

		g[i] = { a, b };
	}

	cout << amt(0) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
