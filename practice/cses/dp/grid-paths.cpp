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

const int MOD = 1e9+7;

void solve() {
    int n;
	cin >> n;

	vec<vec<int>> grid(n, vec<int>(n));
	loop(i,0,n) {
		string s;
		cin>>s;
		loop(j,0,n) grid[i][j] = s[j]=='.';
	}

	loop(i,0,n) loop(j,0,n) {
		if (i==0&&j==0) continue;

		int val = 0;
		if (grid[i][j]) {
			if (i > 0) val += grid[i-1][j];
			if (j > 0) val += grid[i][j-1];
			val %= MOD;	
		}
		grid[i][j] = val;
	}

	cout << grid[n-1][n-1] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
