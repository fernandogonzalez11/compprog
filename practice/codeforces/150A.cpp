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

vec<int> f, e;

void factor(int n) {
	f.clear();
	e.clear();

	int q2 = n;

	for (int d = 2; d * d <= n; d++) {
		if (n % d != 0) continue;

		f.push_back(d);
		e.push_back(1);
		n /= d;
		while (n % d == 0) {
			n /= d;
			e[e.size()-1]++;
		}
	}

	if (n > 1) {
		f.push_back(n);
		e.push_back(1);
	}
}

void solve() {
    int q;
	cin >> q;

	factor(q);

	// printarr(f);
	// printarr(e);

	if (!f.size() || f.size() == 1 && e[0] == 1) {
		cout << "1\n0\n";
		return;
	}

	// e[0] > 1
	if (f.size() == 1) {
		if (e[0] > 2) cout << "1\n" << f[0]*f[0] << "\n";
		else cout << "2\n";
		return;
	}
	
	if (f.size() == 2) {
		if (e[0] == 1 && e[1] == 1) cout << "2\n";
		else cout << "1\n" << f[0]*f[1] << "\n";
	}

	if (f.size() > 2) {
		cout << "1\n" << f[0]*f[1] << "\n";
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
