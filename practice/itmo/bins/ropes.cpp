#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF 1 << 30 + 1 << 25

using namespace std;

bool ok(double x, vec<int> &ropes, int k) {
	int tot = 0;
	for (int rope : ropes) tot += floor((double) rope / x);

	return tot >= k;
}

double binsearch(vec<int> &ropes, int k) {
	// ok(x): whether i can get k ropes of size x amongst all ropes
	// 111111000
	// ok(l) = 1
	// ok(r) = 0
	double l = 0; // i can get any amount of ropes of size 0 (xd)
	double r = 1e8; // limit is a[i] = 1e7, bump a little more
	// since we're working with reals, let's use a fixed amount of iterations, 100 is fine
	loop(i, 0, 100) {
		double mid = (r - l) / 2 + l;
		if (ok(mid, ropes, k)) l = mid;
		else r = mid;
	}
	// return last 1
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	vec<int> ropes(n);
	loop(i, 0, n) cin >> ropes[i];

	cout << setprecision(20) << binsearch(ropes, k) << "\n";

	return 0;
}
