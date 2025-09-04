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

// O(64n)
vec<int> solve() {
    int n, k; cin >> n >> k;

	// k at most 10^18
	// trust the process bro

	vec<int> a(n); loop(i,0,n) cin >> a[i];

	int ops = 0;

	for (int b = 0; b <= 63; b++) {
		for (int i = 0; i < n; i++) {
			if (ops + (1LL<<b) > k) return a;
			if ((a[i] & (1LL<<b)) == 0) {
				ops += (1LL<<b);
				a[i] |= (1LL<<b);
				// cout << "ai turns " << a[i] << " ops turns " << ops << "\n";
			}
		}
	}

	return a;
}

// O(n)
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) {
		vec<int> s = solve();
		int sum = 0;
		for (int i : s) {
			// cout << i << "\n";
			sum += (ll) __builtin_popcountll(i);
		}

		cout << sum << "\n";
	}

	return 0;
}
