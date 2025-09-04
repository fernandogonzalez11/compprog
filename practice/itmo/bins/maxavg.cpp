#include <bits/stdc++.h>

typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define INF (1 << 30) + (1 << 25)
#define int long long

#define EPS 1e-9

using namespace std;

vec<int> a;
int n, d;

int final_l, final_r;

vec<double> create_pref(double x) {
	vec<double> p(n);
	p[0] = a[0] - x;
	loop(i, 1, n) p[i] = p[i - 1] + (a[i] - x);
	return p;
}

void get_segment(double x) {
	vec<double> p = create_pref(x);
	vec<double> m(n);
 
	final_l = final_r - d + 1;
 
	for (; final_l > 0; final_l--) {
		double sum_segment = p[final_r] - p[final_l - 1];
		if (sum_segment >= 0) break;
	}
 
	cout << final_l + 1 << " " << final_r + 1 << "\n"; // convert to 1-based
}

bool ok(double x) {
	vec<double> p = create_pref(x);
	vec<double> m(n);
	m[0] = min(0.0, p[0]);
	loop(i, 1, n) m[i] = min(m[i - 1], p[i]);

	for (int r = n-1; r >= d-1; r--) {
		double sum_segment;
		if (r == d - 1) sum_segment = p[r]; // segment from 0 to r
		else sum_segment = p[r] - m[r - d];

		if (sum_segment >= 0) {
			final_r = r;
			return true;
		}
	}

	return false;
}


void solve() {
	cin >> n >> d;
	a.resize(n);
	loop(i, 0, n) cin >> a[i];

	double l = 0, r = 110;

	for (int i = 0; i < 110; i++) {
		double m = (l + r) / 2;
		if (ok(m)) l = m;
		else r = m;
	}

	// cout << l << "\n";
	ok(l);
	get_segment(l);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
