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

int solve() {
    int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	if (v[0] == v[n-1]) {
		int l = 0;
		for (; l < n; l++) {
			if (v[l] != v[0]) break;
		}

		if (l == n) return 0;

		int r = n-1;
		for (; r >= 0; r--) {
			if (v[r] != v[n-1]) break;
		}

		if (r < 0) return 0;

		return r-l+1;
	} else {
		int l1 = 0;
		for (; l1 < n; l1++) {
			if (v[l1] != v[0]) break;
		}

		if (l1 == n) return 0;

		int r2 = n-1;
		for (; r2 >= 0; r2--) {
			if (v[r2] != v[n-1]) break;
		}

		if (r2 < 0) return 0;

		// l1 to end
		// start to r2
		return min((n-1)-l1+1, r2-0+1);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}
