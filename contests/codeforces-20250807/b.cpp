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

	int a;
	cin >> a;

	int l = a-x, r = a+x;

	int changes = 0;
	loop(i,1,n) {
		cin >> a;
		// inters
		l = max(l, a-x);
		r = min(r, a+x);
		if (l > r) {
			changes++;
			l = a-x;
			r = a+x;
		}
	}

	cout << changes << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
