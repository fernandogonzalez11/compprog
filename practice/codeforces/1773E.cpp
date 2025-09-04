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

	vec<vec<int>> tows(n);
	vec<int> ord;

	loop(i,0,n) {
		int k;
		cin >> k;

		tows[i] = vec<int>(k);

		loop(j,0,k) {
			cin >> tows[i][j];
			ord.push_back(tows[i][j]);
		}
	}

	sort(ord.begin(), ord.end());

	int s = 0;
	loop(i,0,n) {
		int k = tows[i].size();
		loop(j,1,k) {
			s += lower_bound(ord.begin(), ord.end(), tows[i][j]) - 1 !=
				lower_bound(ord.begin(), ord.end(), tows[i][j-1]);
		}
	}

	cout << s << " " << (n+s-1) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
