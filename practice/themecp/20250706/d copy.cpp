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
    int n;
	cin >> n;

	int glbOr = 0;

	vec<pair<int, int>> v(n);
	loop(i,0,n) {
		cin >> v[i].F;
		v[i].S = i;
	}

	sort(v.begin(), v.end());

	int l = 0, r = 1;
	int m = 1;
	while (r < n) {
		while (v[r].F == v[l].F) r++;
		r--;
		m = max(v[r].S-v[l].S, m);
		l = r+1;
		r = r+2;
	}	

	cout << m << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
