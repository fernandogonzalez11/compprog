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

void solve() {
    int n,l,r,k;
	cin >> n >> l >> r >> k;

	if (n == 2) {
		cout << -1 << "\n";
		return;
	}

	if (n%2 == 0) {
		int nextPos = __builtin_clzll(0) - __builtin_clzll(l);
		int nextNum = 1LL<<nextPos;
		if (nextNum > r) cout << -1 << "\n";
		else {
			cout << ((k >= n-1) ? nextNum : l) << "\n";
		}
	} else {
		cout << l << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
