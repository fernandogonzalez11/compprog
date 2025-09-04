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

using namespace std;

int n, m;
vec<vec<pair<int, double>>> g;
vec<int> parent;

bool ok(double x) {
	// for each doable path, check if sum(c_i - x) <= 0
	// obs: graph is acyclic
	// calculate min sums for each node
	// where each index will have the best sum(c_i - x) for each path
	// that ends there

	// pair<node, sum>
	vec<double> minSums(n, INF);
	minSums[0] = 0.0;

	for (int node = 0; node < n; node++) {
		if (node == n-1 && minSums[n-1] <= 0) {
			// cout << "for x=" << x << ": ";
			// loop(i,0,minSums.size()) cout << minSums[i] << " ";
			// cout << "\n";
			return true;
		}
		for (auto ngb : g[node]) {
			double newMinSum = minSums[node] + (ngb.S - x);
			// cout << "newMinSum for node " << ngb.F << ": " << newMinSum << "\n";
			if (newMinSum < minSums[ngb.F]) {
				minSums[ngb.F] = newMinSum;
				parent[ngb.F] = node;
			}
		}
	}

	return false;	
}

void solve() {
	cin >> n >> m;
	g.resize(n);
	parent.resize(n);
	parent.assign(n, -1);

	loop(i,0,m) {
		int a, b;
		double c;
		cin >> a >> b >> c;
		g[--a].push_back({ --b,  c });
	}

	// binsearch to find the min avg
	double l = -1, r = 110;
	for (int i = 0; i <= 110; i++) {
		double m = (r-l)/2+l;
		if (ok(m)) r = m;
		else l = m;

		// cout << l << " " << r << "\n";
	}

	ok(r);
	// cout << r << "\n";

	vec<int> path;
	for (int node = n-1; node != -1; node = parent[node])
		path.push_back(node);

	cout << path.size() - 1 << "\n";
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i]+1 << " ";

	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
