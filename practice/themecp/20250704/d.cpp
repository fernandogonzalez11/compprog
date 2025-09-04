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
	int n;
	cin >> n;

	set<int> distinct;
	
	loop(i,0,n) {
		int x; cin >> x;
		distinct.insert(x);
	}

	// set already sorted
	vector<int> v(distinct.begin(), distinct.end());
	
	// sort(v.begin(), v.end());

	int m = 1;
	for (int num : v) {
		int amt = upper_bound(v.begin(), v.end(), num)
			- lower_bound(v.begin(), v.end(), num - (n-1));
		
		m = max(m, amt);
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
