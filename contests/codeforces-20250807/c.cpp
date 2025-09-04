#include <bits/stdc++.h>
#include <cmath>

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
    int x,y,k;
	cin >> x >> y >> k;

	while (k > 0) {
		int toNext = min(k, (x/y+1) * y - x);
		k -= toNext;
		x += toNext;

		while (x % y == 0) {
			x /= y;
		}

		// cout << x << " " << k << "\n";


		if (x < y) {
			k %= (y-1);
			int res = x + k;
			if (res >= y) {
				res -= y;
				res++;
			}
			cout << res << "\n";
			return;
		}
	}

	cout << x << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
