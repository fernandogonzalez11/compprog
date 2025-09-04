#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

void apply1(vec<int> &a, int i) {
	a[i]--;
	if (i + 1 < a.size()) a[i+1]--;
}

void apply2(vec<int> &a, int i) {
	a[i] -= 2;
}

void solve() {
    int n; cin >> n;
	vec<int> a(n); loop(i,0,n) cin >> a[i];

	bool cant = false;

	loop(i,0,n) {
		int x = a[i];
		if (x < 0) {
			cant = true;
			break;
		} else if (x == 0) {
			// nothing
		} else {
			// apply a bunch of 2 coupons until 0 or 1
			x %= 2;
			if (x == 1) {
				if (i == n-1) {
					cant = true;
					break;
				}
				apply1(a, i);
			}
		}
	}

	cout << (cant ? "NO" : "YES") << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
