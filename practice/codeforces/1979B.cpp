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

int x, y;

bool ok(int k) {
	return ((x+k) ^ (y+k)) == (x ^ y);
}

void solve() {
	
	cin >> x >> y;

	// n1 xor n2 = (n1+1) xor (n2+1) = ... = (n1+k) xor (n2+k) = x xor y
	// int start = x^y;

	// int l = 0, r = 1;
	// while (ok(r)) r *= 2;

	// while (r-l>1) {
	// 	int m = (r-l)/2+l;
	// 	if (ok(m)) l = m;
	// 	else r = m;
	// }

	// cout << 2*(l+1) << "\n";

	// n1 ^ n2 = x ^ y
	// => n2 = x ^ y ^ n1
	// when testing this for n1 = 0,1,... we incur in a cyclic behavior
	/*
	>>> 57^37^0				*** l = 0
	28
	>>> 57^37^1
	29
	>>> 57^37^2
	30
	>>> 57^37^3
	31
	>>> 57^37^4
	24
	>>> 57^37^5
	25
	>>> 57^37^6
	26
	>>> 57^37^7				*** r = 7
	27
	*/
	// l is 0 => 
	int nl = x^y^0;
	// find r
	// x^y ^ r = nl-1 =>
	int r = (nl-1)^x^y;
	// the size is half of the size from 0 to r:
	cout << (r+1)/2 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
