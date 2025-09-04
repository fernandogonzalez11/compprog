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

void solve() {
    int n, k; cin >> n >> k;
	vec<int> h(n); loop(i,0,n) cin >> h[i];
	vec<int> d(n); loop(i,0,n) cin >> d[i];

	vec<pair<int, int>> dh(n);
	loop(i,0,n) {
		dh[i] = { abs(d[i]), h[i] };
	}

	sort(dh.begin(), dh.end());

	loop(i,0,n) {
		d[i] = dh[i].F;
		h[i] = dh[i].S;
	}

	// loop(i,0,n) cout << d[i] << " " << h[i] << "\n";
	// cout << "--\n";

	int pos = 0;
	int i = 0;
	int k_rn = k;
	bool can = true;
	while (i < n) {
		if (d[i] - pos <= 0) {
			can = false;
			break;
		}

		// shoot as many monsters
		while (k_rn > 0 && i < n) {
			int amt = min(k_rn, h[i]);
			h[i] -= amt;
			k_rn -= amt;
			
			if (h[i] == 0) i++;
		}

		// reset and next position
		k_rn = k;
		pos++;
	}

	cout << (can ? "YES": "NO") << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
