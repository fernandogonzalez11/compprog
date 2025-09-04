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

int solve() {
    int n, m, k;
	cin >> n >> m >> k;

	// vec<int> a(n+1);

	// loop(i,0,m+1) {
	// 	a[n+1-1] = i;
	// 	for (int j = n-1; j >= 0; j--) {
	// 		a[j] = a[j+1] % (j+1);
	// 	}

	// 	printarr(a);
	// }

	if (k == 1) {
		return 1;
	} else if (k == 2) {
		if (m < n) return m;

		// nums between 0 and n that dont divide n
		int cnt = n-1;
		// nums between n and m that divide n
		cnt += (m / n);

		return cnt;
	} else if (k == 3) {
		if (m < n) return 0;

		// nums between n and m that divide n
		int cnt = (m / n);
		cnt = m-n+1 - cnt;

		return cnt;
	} else {
		return 0;
	}

	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}
