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
	cin>>n;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];


	// cout << "---\n";

	int s = accumulate(v.begin(),v.end(),0LL);
	int x = 0;
	int nosacrifice = -INF;
	int l=0, r=1;
	vec<bool> vis(n,false);
	loop(_,0,n-2) {
		// cout << l << " " << r << "\n";

		int signl = v[l]>=0, signr = v[r]>=0;
		if (signl&&signr) {
			// (+) +
			nosacrifice = max(nosacrifice, x - (s-v[l]));
			x += v[l];
			s -= v[l];
			vis[l]=true;
		} else if (signl&&!signr) {
			// + (-)
			nosacrifice = max(nosacrifice, x - (s-v[l]));
			nosacrifice = max(nosacrifice, x+v[l] - (s-v[l]-v[r]));
			x += -v[r];
			s -= v[r];
			vis[r]=true;
		} else if (!signl&&signr) {
			// (-) + -> sacrifice
			// if i dont sacrifice, i must commit to decrease all the rest
			// so simulate like i made that
			nosacrifice = max(nosacrifice, x - (s-v[l]));
			x += v[l];
			s -= v[l];
			vis[l]=true;
		} else {
			// - (-)
			nosacrifice = max(nosacrifice, x - (s-v[l]));
			nosacrifice = max(nosacrifice, x+v[l] - (s-v[l]-v[r]));
			x += -v[r];
			s -= v[r];
			vis[r]=true;
		}

		while (vis[l]) l++;
		r = max(r,l+1);
		while (vis[r]) r++;
	}

	// last movement
	x = max(x+v[l],x-v[r]);

	// printarr(v);
	// printarr(vis);
	cout << max(x, nosacrifice) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
