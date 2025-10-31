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

const int MOD = 1000000007;

void solve() {
    /*
	1st type takes from max
	2nd type takes from min

	a > b
	make a == b with type 1s
	use type 2 -> a-1 a
	use type 1 -> a-1 a-1
	and so on...
	*/

	int a, b, n, m;
	cin >> a >> b >> n >> m;

	if (a+b < n+m) {
		cout << "No\n";
		return;
	}

	if (a < b) swap(a,b);
	if (a-b <= n) {
		n -= a-b;
		a = b;

		int mm = min(n, m);
		n -= mm;
		m -= mm;
		a -= mm;
		b -= mm;

		// cout << a << " " << b << " " << n << " " << m << "\n";

		if (n != 0) {
			cout << (((a+b) >= n) ? "Yes\n" : "No\n");
			return;
		} else {
			cout << (min(a,b) >= m ? "Yes\n" : "No\n");
		}
	} else {
		cout << (b >= m ? "Yes\n" : "No\n");
	}
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
