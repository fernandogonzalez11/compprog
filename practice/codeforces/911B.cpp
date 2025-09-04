#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

bool can(int k, int n, int a, int b) {
	if (k == 0) return true;
	return (a/k + b/k) >= n && a >= k && b >= k;
}

// form 1 1 1 1 0 0 0 0
// find last 1
int bsearch(int n, int a, int b) {
	int l = 1, r = max(a,b)+1;
	while (l < r - 1) {
		int m = (r-l)/2 + l;
		// cout << l << " " << r << " " << m << "\n";
		if (can(m, n, a, b)) l = m;
		else r = m;
	}

	return l;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
	// loop(i,0,max(a,b)+1) cout << can(i, n, a, b) << " ";

	int s = bsearch(n, a, b);
	cout << s << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t = 1;// cin >> t;
    while (t--) solve();

	return 0;
}
