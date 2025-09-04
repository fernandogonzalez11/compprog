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

bool solve() {
    int n, k;
	cin >> n >> k;

	vec<pair<int,int>> v(n);
	loop(i,0,n) cin >> v[i].F;
	loop(i,0,n) cin >> v[i].S;

	sort(v.begin(), v.end());

	vec<int> vh(n), vp(n);
	loop(i,0,n) {
		vh[i] = v[i].F;
		vp[i] = v[i].S;
	}

	// printarr(vh);

	for (int i = n-2; i >= 0; i--) {
		vp[i] = min(vp[i+1], vp[i]);
	}

	// printarr(vp);

	int acc = k;

	while (true) {
		int i = upper_bound(vh.begin(), vh.end(), acc) - vh.begin();
		// cout << i << "\n";

		if (i == n) return true;

		k -= vp[i];
		if (k < 0) return false;

		acc += k;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << "\n";

	return 0;
}
