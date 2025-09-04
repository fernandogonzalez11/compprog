#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

int n, k;
vec<int> l, r;

// amt of numbers that are strictly less than x
int calc(int x) {
	int s = 0;
	loop(i,0,n) {
		if (x <= l[i]) {}
		else if (l[i] < x && x <= r[i]) 
			s += x - l[i];
		else
		 	s += r[i] - l[i] + 1;
	}

	return s;
}

bool ok(int x) {
	return calc(x) <= k;
}

void solve() {
	cin >> n >> k;

	l.resize(n);
	r.resize(n);
	loop(i,0,n) cin >> l[i] >> r[i];

	int le = -1, ri = 1;
	while (!ok(le)) le *= 2;
	while (ok(ri)) ri *= 2;

	// cout << ri << "\n";

	while (ri - le > 1) {
		int m = (ri - le)/2+le;
		if (ok(m)) le = m;
		else ri = m;
	}

	cout << le << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
