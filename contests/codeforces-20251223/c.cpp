#include <algorithm>
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

bool ok(int m, vec<int> v) {

}

void solve() {
    int n;
	cin>>n;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	sort(v.begin(),v.end());
	// int l = v[0], r = v[1]+1;
	// while (r-l>1) {
	// 	int m = (r-l)/2+l;
	// 	// VVVVVFFFF
	// 	if (ok(m,v)) l = m;
	// 	else r = m;
	// }

	// printarr(v);
	// loop(i,1,n) v[i]-=v[0];
	// printarr(v);
	cout << max(v[0],v[1]-v[0]) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
