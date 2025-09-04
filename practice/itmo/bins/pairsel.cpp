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
vec<pair<double, double>> v;

double calc(pair<double, double> &a, double x) {
	return a.F - x * a.S;
}

bool ok(double x) {
	sort(v.begin(), v.end(), [&](pair<double, double> &a, pair<double, double> &b) {
		return calc(a, x) > calc(b, x);
	});

	double s = 0;
	loop(i,0,k) s += calc(v[i], x);

	return s >= 0;
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	
	loop(i,0,n) cin >> v[i].F >> v[i].S;

	double l = 0, r = 1;
	while (ok(r)) r *= 2;

	for (int i = 0; i <= 100; i++) {
		double m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	cout << setprecision(11) << l << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
