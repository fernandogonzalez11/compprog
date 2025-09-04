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

void solve() {
    int n, x;
	cin >> n >> x;

	if (n == 1) {
		cout << (x ? x : -1) << "\n";
		return;
	}

	// n guaranteed to be 2+

	// set all 1s necessary
	int s = x;

	int rem = max(0LL, n - __builtin_popcountll(x));

	// cout << rem << "\n";

	// odd
	if (rem & 1) {
		s += (rem-1) * 1;
		
		int i = 0;
		while (true) {
			int zeros;
			// all rem except 1 are used
			// at most 1 elem in n - rem is used for x
			if (i == 0) zeros = 1 + (n - rem) - (x & 1);
			// all rem are unused
			// at most 1 elem in n - rem is used for x
			else zeros = n - (x & (1LL << i));

			// cout << "z:" << zeros << "\n";

			if (zeros > 1) break;
			i++;
		}

		s += 2 * (1LL << i);
	// even
	} else {
		s += rem * 1;
	}

	cout << s << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
