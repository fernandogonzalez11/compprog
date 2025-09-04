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
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	sort(v.begin(), v.end());

	int mult1 = v[0], mult2 = -1;
	loop(i,1,n) {
		if (v[i] % mult1 != 0) {
			mult2 = v[i];
			break;
		}
	}

	if (mult2 == -1) {
		cout << "Yes\n";
		return;
	}

	loop(i,0,n) {
		if (!(v[i] % mult1 == 0 || v[i] % mult2 == 0)) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
