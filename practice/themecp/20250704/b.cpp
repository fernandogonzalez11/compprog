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
	vec<int> low(26, 0), upp(26, 0);
	int n, k; cin >> n >> k;
	loop(i,0,n) {
		char c; cin >> c;
		if ('A' <= c && c <= 'Z') upp[c - 'A']++;
		else low[c - 'a']++;
	}

	// printarr(low);
	// printarr(upp);

	int burls = 0;
	loop(i,0,26) {
		// if (!low[i] || !upp[i]) continue;
		if (low[i] == upp[i]) burls += low[i];
		else if (low[i] < upp[i]) {
			int x = (upp[i] - low[i]) / 2;
			x = min(k, x);
			burls += low[i] + x;
			k -= x;
		} else {
			int x = (low[i] - upp[i]) / 2;
			x = min(k, x);
			burls += upp[i] + x;
			k -= x;
		}
	}

	cout << burls << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
