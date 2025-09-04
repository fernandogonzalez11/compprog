#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL<<62)
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	int k = v[0];
	int l = 1, r = 1;
	int minRes = INF;
	loop(i,1,n) {
		if (v[i] == k) r++;
		else {
			// calc
			int calc = (l-1 + n-r)*k;
			minRes = min(minRes, calc);
			k = v[i];
			l = i+1;
			r = i+1;
		}
	}

	// one more time
	int calc = (l-1 + n-r) * k;
	minRes = min(minRes, calc);

	if (l == 1 && r == n) cout << 0 << "\n";
	else cout << minRes << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
