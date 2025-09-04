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
    int n, k;
	cin >> n >> k;
	vec<int> p(n);
	loop(i,0,n) cin >> p[i];

	int amt = 0;

	loop(i,0,n) {
		// cout << i << "\n";
		if (p[i] || i + k - 1 >= n) continue;
		bool doamt = true;
		int j = 0;
		for (; j < k; j++) {
			if (p[i+j]) {
				doamt = false;
				break;
			}
		}
		amt += (int) doamt;
		i += j;
	}

	cout << amt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
