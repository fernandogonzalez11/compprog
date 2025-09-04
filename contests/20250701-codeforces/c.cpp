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

using namespace std;

void solve() {
    // obs: for min/max always guaranteed
	// obs: both extremes r always satisfied
	int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	vec<int> mpref(n), Msuf(n);
	mpref[0] = v[0];
	loop(i,1,n) mpref[i] = min(mpref[i-1], v[i]);

	Msuf[n-1] = v[n-1];
	for (int i = n-2; i >= 0; i--)
		Msuf[i] = max(Msuf[i+1], v[i]);

	// loop(i,0,n) cout << mpref[i] << " " << Msuf[i] << "\n";
	loop(i,0,n) {
		if (i == 0) {
			cout << 1;
		} else if (i == n-1) {
			cout << 1;
		} else {
			int m = mpref[i-1], M = Msuf[i+1];
			cout << (v[i] <= m || v[i] >= M);
		}
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
