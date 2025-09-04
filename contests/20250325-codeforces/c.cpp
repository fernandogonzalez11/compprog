#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void proc() {
	ll x; cin >> x;

	int ones = 0, zeros = 0;
	ll y = 0;

	ll c = x;
	while (c > 0) {
		int v = c & 1;
		if (v) {
			if (!ones) y |= (1LL << (ones + zeros));
			ones++;
		}
		else if (!v) {
			y |= (1LL << (ones + zeros));
			zeros++;
		}
		c >>= 1;
	}

	if (ones < 2 || zeros == 0 || y >= x) cout << "-1" << "\n";
	else cout << y << "\n";

	// ll z = x ^ y;
	// cout << (x + y > z && x + z > y && y + z > x) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
