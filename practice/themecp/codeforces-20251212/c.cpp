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
    /*int a=0, b=1;
	int fcnt = 2;
	while (b < 2*1e5) {
		int c = a+b;
		a = b;
		b = c;
		fcnt++;
	}

	cout << fcnt << "\n";*/

	int n,k;
	cin >> n >> k;
	if (k >= 35) {
		cout << 0 << "\n";
		return;
	}

	int cnt = 0;
	for (int q = 0; q <= n; q++) {
		int fk = n, fprev = q;
		int cool = true;
		for (int i = k-2; i > 0; i--) {
			int fu = fk-fprev;
			if (fu < 0 || (fu == 0 && i > 1) || fu > fprev) {
				cool = false;
				break;
			}
			fk = fprev;
			fprev = fu;
		}
		// cout << q << " " << cool << "\n";
		cnt += cool;
	}

	cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
