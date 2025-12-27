#include <bits/stdc++.h>
#include <numeric>

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
    array<int,3> a;
	loop(i,0,3) cin >> a[i];
	sort(a.begin(),a.end());
	int dif = min(a[1]-a[0], a[2]-a[1]);
	if (a[1]-a[0] == a[2]-a[1]) cout << a[2]+dif << "\n";
	else cout << (4*a[0]+6*dif-accumulate(a.begin(),a.end(),0)) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
