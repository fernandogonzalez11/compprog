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

bool isSym(int n) {
	int amt = __builtin_clzll(0LL) - __builtin_clzll(n);
	int r = amt-1, l = 0;

	while (l < r) {
		if (
			((n & (1LL<<l)) > 0) ^
			((n & (1LL<<r)) > 0)
		) return false;
		l++;
		r--;
	}
	return true;
}

void solve() {
    int n;
	cin >> n;

	int n2 = n;
	loop(i,0,32) {
		if ((n&1) == 0) n >>= 1;
		else break;
	}

	int amt = __builtin_clzll(0LL) - __builtin_clzll(n);
	// cout << n << " " << amt << "\n";

	if (isSym(n)) {
		if (amt%2 == 0) cout << "YES\n";
		else if ((n & (1LL<<(amt/2))) == 0) cout << "YES\n";
		else cout << "NO\n";
	} else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
