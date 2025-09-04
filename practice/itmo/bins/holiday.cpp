#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

int m, n; 
vec<vec<int>> v(0, vec<int>(3));

int balloons(int i, int t) {
	vec<int> vals = v[i];
	int ti = vals[0], zi = vals[1], yi = vals[2];

	int T = ti * zi + yi;
	return t/T * zi + min(zi, (t%T) / ti);
}

bool ok(int t) {
	int s = 0;
	loop(i,0,n) s += balloons(i, t);

	return s < m;
}

int binsearch() {
	// l is 1, r is 0
	// find first 0
	int l = -1, r = 1;
	// cout << "dbg: " << ok(-1) << "\n";
	while (ok(r)) r *= 2;

	while (r - l > 1) {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	return r;
}

void solve() {
    cin >> m >> n;

	v.resize(n);

	loop(i,0,n) {
		int t, z, y;
		cin >> t >> z >> y;
		v[i] = { t, z, y};
	}

	int val = binsearch();
	cout << val << "\n";

	int s = m;
		
	loop(i,0,n) {
		int x = balloons(i, val);
		cout << max(0LL, min(s, x)) << " ";
		s -= x;
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
