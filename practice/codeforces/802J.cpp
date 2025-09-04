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

// vec<int> dp;
vec<vec<pair<int, int>>> g;

// int sol(int node) {
// 	cout << "a:" << node << "\n";
// 	if (g[node].size() == 0) return 0;

// 	pair<int,int> u = g[node][0];
// 	int left = sol(u.F);

// 	if (g[node].size() == 1) return left + u.S;

// 	pair<int,int> v = g[node][1];
// 	int right = sol(v.F);

// 	return max(left + u.S, right + v.S);
// }

void solve() {
    int n;
	cin >> n;

	// dp.resize(n, -1);
	g.resize(n);

	loop(i,0,n-1) {
		int u,v,c;
		cin >> u >> v >> c;

		g[u].push_back({v,c});
		g[v].push_back({u, c});
	}
	
	// cout << sol(0) << "\n";

	// printarr(dp);

	bool vis[n];
	fill(vis, vis+n, false);

	queue<pair<int,int>> q;
	q.push({0, 0});
	vis[0] = true;

	int M = -1;

	

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		// cout << p.F << " " << p.S << "\n";

		vec<pair<int,int>> ngbs = g[p.F];
		if (ngbs.size() == 1) M = max(M, p.S);

		for (auto ngb : ngbs) {
			if (vis[ngb.F]) continue;
			vis[ngb.F] = true;
			q.push({ ngb.F, p.S + ngb.S });
		}
	}

	cout << M << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
