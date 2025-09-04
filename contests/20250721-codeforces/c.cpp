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

int l, r;

int dc(int x) {
	return r/x - (l-1)/x;
}

void solve() {
	cin >> l >> r;

	int c = r-l+1;
	int u = 0;
	u += dc(2) + dc(3) + dc(5) + dc(7);
	u -= dc(2*3) + dc(2*5) + dc(2*7) + dc(3*5) + dc(3*7) + dc(5*7);
	u += dc(2*3*5) + dc(2*3*7) + dc(2*5*7) + dc(3*5*7);
	u -= dc(2*3*5*7);
	c -= u;

	cout << c << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
