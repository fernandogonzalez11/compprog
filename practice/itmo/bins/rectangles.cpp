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

bool ok(ll w, ll h, ll n, ll x) {
	// if we can fit n rectangles in the x * x square
	// by packing them like a grid (most optimal)
	return (x / w) * (x / h) >= n;
}

ll binsearch(ll w, ll h, ll n) {
	// invariant:
	// ok(l) = 0
	// ok(r) = 1
	ll l = 0; // 0 x 0 square will never hold any rectangles
	ll r = 1;
	while (!ok(w, h, n, r)) r <<= 1;

	while (r - l > 1) {
		ll mid = (r - l) / 2 + l;
		// 000000111111
		if (ok(w, h, n, mid)) r = mid;
		else l = mid;
	}
	// return first 1
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll w, h, n; cin >> w >> h >> n;
	cout << binsearch(w, h, n) << "\n";

	return 0;
}
