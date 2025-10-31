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
    int x, y;
	cin >> x >> y;

	int pos = x;
	int disp = 1;
	bool s = 1;
	int tot = 0;
	while (pos != y) {
		// cout << pos << "\n";
		bool oneside = (pos - y) >= 0;

		int newpos = x +  (s?1:-1) * disp;

		tot += abs(newpos-pos);
		pos = newpos;
		s = !s;
		disp <<= 1;

		bool otherside = (pos - y) >= 0;

		if (oneside ^ otherside) {
			tot -= abs(pos - y);
			break;
		}
	}

	cout << tot << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
