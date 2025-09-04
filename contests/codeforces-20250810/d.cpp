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
    // 2 nodes: 0
	// 3+ nodes: check if all paths to leaves are 1
	// otherwise all paths to leaves need to be compressed
	// size(compPaths)-1

	int n;
	cin >> n;

	vec<vec<int>> g(n);
	loop(i,0,n-1) {
		int a,b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if (n == 2) {
		cout << "0\n";
		return;
	}

	int leafC = 0;
	set<int> prnts;

	// O(n)
	loop(i,0,n)
		if (g[i].size() == 1) {
			prnts.insert(g[i][0]);
			leafC++;
		}

	// printarr(leaves);

	// O(nlogn * ???)
	int lfs1 = 0;
	for (int p : prnts) {
		int lfs1P = 0;
		for (int ch : g[p])
			lfs1P += (g[ch].size() == 1);

		lfs1 = max(lfs1, lfs1P);
	}

	cout << leafC - lfs1 << "\n";
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
