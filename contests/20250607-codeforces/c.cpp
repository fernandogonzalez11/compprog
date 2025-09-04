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

int n, k;
vec<int> v;
int imat;
int w;

bool ok(int i) {
	return ((w + abs(v[i] - imat)) > imat + 1);
}

bool solve() {

	cin >> n >> k;
	v.resize(n);
	int M = -1;
	loop(i,0,n) {
		cin >> v[i];
		M = max(M, v[i]);
	}

	imat = v[k-1];

	sort(v.begin(), v.end());
	// printarr(v);

	int start = 0;
	for (; v[start] != imat; start++);

	w = 1;

	// cout << imat << "\n";

	loop(i,0,n+1) {
		// first 1 - 1
		int l = start, r = n-1;
		while (r - l > 1) {
			int m = (r-l)/2+l;
			if (ok(m)) r = m;
			else l = m;
		}

		// cout << ok(l) << ok(r) << "\n";

		if (ok(l) && ok(r)) return false;

		int choose = 0;

		if (ok(r)) choose = l;
		else choose = r;

		w += v[choose] - imat;
		imat = v[choose];
		start = choose;

		if (imat == M) return true;

		// cout << w << "\n";
	}

	

	// cout << imat << "\n";

	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
