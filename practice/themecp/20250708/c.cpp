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
    int n, m, k;
	cin >> n >> m >> k;
	int maxDist;
	if (k <= n) maxDist = 1;
	else maxDist = k/n + (k%n > 0);

	// cout << maxDist << "\n";
	int a = maxDist, b = m - maxDist + 1;
	cout << max(1LL, a/b + (a%b > 0)) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
