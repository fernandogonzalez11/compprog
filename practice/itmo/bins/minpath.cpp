#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

int n, m, d;
vec<vec<pair<int, int>>> g;

void replicate_path(int k) {
	queue<vec<int>> q;
	vec<bool> vis(n, false);
	q.push({ 0 });
	while (!q.empty()) {
		vec<int> p = q.front();
		q.pop();

		int node = p[p.size() - 1];
		vis[node] = true;

		if (node == n-1) {
			cout << p.size() - 1 << "\n";
			for (int nn : p) cout << nn+1 << " ";
			cout << "\n";
			return;
		} else if (p.size() > d) continue;

		for (auto ngb : g[node]) {
			if (!vis[ngb.F] && ngb.S <= k) {
				vec<int> vcopy = p;
				vcopy.push_back(ngb.F);
				q.push(vcopy);
			}
		}
	}
}

bool ok(int k) {
	// can i make a path of <= d edges, where all nodes are <= r?
	// make a bfs, closing a path when the edge is > r
	// get # of edges of first path to make it to n, check if <= d

	queue<pair<int, int>> q;
	vec<bool> vis(n, false);
	q.push({ 0, 0 });
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		// cout << p.F << " " << p.S << "\n";
		vis[p.F] = true;

		if (p.F == n-1)
			return p.S <= d;
		else if (p.S > d) continue;

		for (auto ngb : g[p.F]) {
			if (!vis[ngb.F] && ngb.S <= k) q.push({ ngb.F, p.S + 1 });
		}
	}

	return false;
}

void solve() {
	cin >> n >> m >> d;

	g.resize(n);
	
	loop(i,0,m) {
		int a, b, c;
		cin >> a >> b >> c;

		a--; b--;
		g[a].push_back({ b, c });
	}

	// for (auto a : g[0]) cout << a.F << " " << a.S << "\n";

	int l = 0, r = 1e9+1;

	while (r - l > 1) {
		int m = (r-l)/2 + l;
		if (ok(m)) r = m;
		else l = m;

		// cout << l << " " << r << " " << m << "\n";
	}

	// cout << r << "\n";

	// we should get FV
	if (!ok(r)) cout << -1 << "\n";
	else replicate_path(r);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
