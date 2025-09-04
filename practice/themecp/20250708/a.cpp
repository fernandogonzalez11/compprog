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

bool solve() {
    int n, m;
	cin >> n >> m;
	vec<int> sets(m, 0);
	loop(i,0,n) {
		loop(j,0,m) {
			char c;
			cin >> c;
			sets[j] |= ((c == 'v') << 0);
			sets[j] |= ((c == 'i') << 1);
			sets[j] |= ((c == 'k') << 2);
			sets[j] |= ((c == 'a') << 3);
		}
	}

	// printarr(sets);

	int searching = 0;
	loop(i,0,m) {
		if (sets[i] & (1 << searching)) searching++;
	}

	return searching >= 4;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
