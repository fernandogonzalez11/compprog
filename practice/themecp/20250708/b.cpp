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

int TESTNUM = 1;

void solve() {
    // get total &
	// if a bit is 1 -> max groups is n
	// if it's 0 -> guarantee that each group has 1+ 0s -> max groups is amount of 0s
	// min of all those bit values

	

	int n;
	cin >> n;

	vec<int> v(n);
	int totStr = ~0;


	loop(i,0,n) {
		cin >> v[i];
		totStr &= v[i];
	}

	loop(b,0,32) if ((totStr >> b) & 1) {
		cout << 1 << "\n";
		return;
	}

	int m = 0;
	int lclAnd = ~0;
	loop(i,0,n) {
		lclAnd &= v[i];
		if (lclAnd == totStr) {
			m++;
			lclAnd = ~0;
		}
	}

	cout << m << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	loop(i,1,t+1) {
		solve();
	}

	return 0;
}
