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

	vec<pair<int,int>> v(n);
	loop(i,0,n) cin >> v[i].F >> v[i].S;

	sort(v.begin(), v.end());
	int best = -1;
	loop(i,0,n) {
		if (best <= v[i].S) best = v[i].S;
		else best = v[i].F;
	}

	cout << best << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
