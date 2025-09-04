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

	int ones = 0, zeros = 0;
	loop(i,0,2*n) {
		int x; cin >> x;
		ones += (x == 1);
		zeros += (x == 0);
	}

	// min: pair ones together
	// either 0 if even, 1 if odd
	int m = ones % 2;
	// max: pair all ones I can with 0s
	int M = min(ones, zeros);

	cout << m << " " << M << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
