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

int n, k;
vec<int> x;

bool ok(int D) {
	int cnt = 1;
	int start = x[0];

	loop(i, 1, n) {
		if (x[i] - start < D) continue;
		cnt++;
		start = x[i];
	}

	return cnt >= k;
}

void solve() {
	cin >> n >> k;

	x.resize(n);
	loop(i,0,n) cin >> x[i];

	sort(x.begin(), x.end());

	int l = 0, r = 1;
	while (ok(r)) r *= 2;

	while (r-l > 1) {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	cout << l << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
