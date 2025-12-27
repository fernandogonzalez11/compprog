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

vec<int> v;
int n;

bool ok(int x) {
	if (x>n) return false;
	return accumulate(v.begin(),v.end(),0)-x+1 >= n;
}	

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	sort(v.begin(),v.end());
	
	loop(i,0,n) cin >> v[i];
	int l = 1, r = 2;
	while (ok(r)) r *= 2;
	while (r-l>1) {
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
	cin >> t;
	while (t--) solve();

	return 0;
}
