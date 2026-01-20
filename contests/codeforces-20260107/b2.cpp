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

int n,k;
vec<int> v;

bool ok(int mex) {
	// find which is the shortest size of a segment that
	// includes 0...mex-1, then check if that segment is <= k
	// only works if the mex < k
	map<int,int> m;

	int l = 0, r = 0;
	for (; r < n; r++) {
		if (v[r] >= mex) continue;
		m[v[r]]++;
		if (m.size() == mex) break;
	}

	if (m.size() < mex) return false;

	// for (auto [k,v]:m) cout << k <<":"<< v << "\n";
	
	int sz = r-l+1;

	r++;
	for (; r < n; r++) {
		m[v[r]]++;
		while (m[v[l]] > 1) {
			m[v[l++]]--;
		}
		sz = min(sz, r-l+1);
	}

	return sz <= k;
}

void solve() {
	cin>>n>>k;
	v.resize(n);
	loop(i,0,n) cin>>v[i];

	int l = 0, r = k-1;

	if (ok(r)) {
		cout << r << "\n";
		return;
	}

	while (r-l>1) {
		int m = (r-l)/2+l;
		// VVVVVVFFFFF
		if (ok(m)) l = m;
		else r = m;
	}

	cout << l << "\n";	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
