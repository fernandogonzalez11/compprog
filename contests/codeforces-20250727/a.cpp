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

void solve() {
    int n,c;
	cin >> n >> c;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	sort(v.begin(), v.end());

	// printarr(v);

	int mult = 0;
	int caught = 0;
	for (int i = n-1; i >= 0; i--) {
		if ((v[i] << mult) <= c) {
			caught++;
			mult++;
		}
	}

	cout << n-caught << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
