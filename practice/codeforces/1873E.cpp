#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

int w(int h, vec<int> pref, int i) {
	return max(0LL, h * (i+1) - pref[i]);
}

bool ok1(vec<int> a, vec<int> pref, int h, int maxW) {
	// binary search to find last that adds value

	int l = 0, r = a.size() - 1;

	if (a[r] <= h)
		return w(h, pref, r) <= maxW;

	while (r - l > 1) {
		int m = (r-l)/2+l;
		// allowed
		if (a[m] < h) l = m;
		// disallowed
		else r = m;
	}

	// cout << "given h=" << h << " testing w upto " << l << "\n";
	// cout << "w is " << w(h, pref, l) << "\n";
	return w(h, pref, l) <= maxW;
}

void solve() {
	// x: max water
    int n, x; cin >> n >> x;
	vec<int> a(n); loop(i,0,n) cin >> a[i];

	sort(a.begin(), a.end());
	vec<int> pref(n);
	pref[0] = a[0];
	loop(i,1,n) pref[i] = pref[i-1] + a[i];

	// loop(i,0,n) cout << pref[i] << " ";
	// cout << "\n";

	// binary search to find height

	int l = 0, r = 1;
	while (ok1(a, pref, r, x)) r <<= 1;

	// cout << "seed r: " << r << "\n";

	while (r - l > 1) {
		int m = (r-l)/2+l;
		// allowed
		if (ok1(a, pref, m, x)) l = m;
		else r = m;
	}

	cout << l << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
