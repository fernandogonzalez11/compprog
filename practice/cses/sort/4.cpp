#include <algorithm>
#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

int n, m, a, x;

void solve() {
    cin >> n >> m;

	multiset<int> h;
	loop(i,0,n) {
		int a; cin >> a;
		h.insert(a); // O(log n)
	}

	// multiset auto sorts

	loop(i, 0, m) {
		cin >> x;

		// lower_bound: first val that is > x
		// last val that is <= x is our desired pick
		// special multiset upper_bound that's actually the desired O(logn)
		auto it = h.upper_bound(x);
		if (it == h.begin()) cout << -1 << "\n";
		else {
			cout << *(--it) << "\n";
			h.erase(it); // O(log m)
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
