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
	// cout << k << "\n"; 
	queue<int> q;
	vec<bool> vis(n, false);
	vec<int> parent(n, -1);
	q.push(0);
	vis[0] = true;
	for (int i = 1; i <= d+1; i++) {
		int t = q.size();
		while (t--) {
			int node = q.front();
			q.pop();

			if (node == n-1) {
				int cur_parent = node;
				vec<int> path;
				while (cur_parent != 0) {
					path.push_back(cur_parent);
					cur_parent = parent[cur_parent];
				}

				cout << path.size() << "\n";
				cout << 1 << " ";
				for (int j = path.size() - 1; j >= 0; j--)
					cout << path[j]+1 << " ";
				cout << "\n";

				return;
			}

			for (auto ngb : g[node]) {
				if (!vis[ngb.F] && ngb.S <= k) {
					vis[ngb.F] = true;
					parent[ngb.F] = node;
					q.push(ngb.F);
				}
			}
		}
	}
}

bool ok(int k) {
	// can i make a path of <= d edges, where all nodes are <= r?
	// make a bfs, closing a path when the edge is > r
	// get # of edges of first path to make it to n, check if <= d

	queue<int> q;
	vec<bool> vis(n, false);
	q.push(0);
	vis[0] = true;
	for (int i = 1; i <= d+1; i++) {
		int t = q.size();
		while (t--) {
			int node = q.front();
			q.pop();

			if (node == n-1) return true;

			for (auto ngb : g[node]) {
				if (!vis[ngb.F] && ngb.S <= k) {
					vis[ngb.F] = true;
					q.push(ngb.F);
				}
			}
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

	// cout << ok(0) << ok(1) << "\n";

	while (r - l > 1) {
		int m = (r-l)/2 + l;
		if (ok(m)) r = m;
		else l = m;

		// cout << l << " " << r << " " << m << "\n";
	}

	// cout << r << "\n";

	// we should get FV
	if (!ok(r)) cout << -1 << "\n";
	else if (ok(l)) replicate_path(l);
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
