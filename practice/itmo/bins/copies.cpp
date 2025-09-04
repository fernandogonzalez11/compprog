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

bool ok(ll t, ll n, ll x, ll y) {
	return t / x + t / y >= n;
}

ll binsearch(ll n, ll x, ll y) {
	// 000001111
	// ok(l) = 0
	// ok(r) = 1
	ll l = 0; // cant do shit in 0 seconds
	ll r = 1;
	while (!ok(r, n, x, y)) r <<= 1;

	while (r - l > 1) {
		ll mid = (r - l) / 2 + l;
		if (ok(mid, n, x, y)) r = mid;
		else l = mid;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, x, y; cin >> n >> x >> y;
	// need to print at least one copy, then i can start working on both of them simultaneously
	if (n == 1) cout << min(x, y) << "\n";
	else cout << min(x, y) + binsearch(n - 1, x, y) << "\n"; 

	return 0;
}
