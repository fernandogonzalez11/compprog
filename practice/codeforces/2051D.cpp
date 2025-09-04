#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

int s = 0, x, y, n;
vec<int> v;

bool ok1(int i, int start) {
	// VVVVVVFFFF
	return x <= s - v[start] - v[i];
}

bool ok2(int i, int start) {
	// FFFFVVVVVV
	return s - v[start] - v[i] <= y;
}

int pairs_binsearch(int start) {
	int l = start, r = n;

	// first binsearch for left extreme
	// VVVVVFFFFF
	// find last V
	while (r-l > 1) {
		int m = (r-l)/2+l;
		if (ok1(m, start)) l = m;
		else r = m;
	}

	if (l == start) return 0;
	int right = l;

	// second binsearch for right extreme
	// FFFFFVVVVVV
	// find first V
	l = start, r = right+1;

	while (r-l > 1) {
		int m = (r-l)/2+l;
		if (ok2(m, start)) r = m;
		else l = m;
	}

	if (r == l+1) return 0;
	int left = r;

	return right - left + 1;
}

void solve() {
	cin >> n >> x >> y;

	v.resize(n);
	loop(i,0,n) {
		cin >> v[i];
		s += v[i];
	}

	sort(v.begin(), v.end());

	loop(i,0,n) {
		cout << i << " " << ok1(i, 0) << " " << ok2(i, 0) << " " << (ok1(i, 0) && ok2(i, 0)) << "\n";
	}

	int res = 0;
	for (int i = 0; i < n-1; i++) {
		res += pairs_binsearch(i);
	}

	cout << res << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
