#include <algorithm>
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

typedef struct uf {
	int *ids, *sizes;

	uf(int n) {
		ids = new int[n];
		sizes = new int[n];

		for (int i = 0; i < n; i++) {
			ids[i] = i;
			sizes[i] = 1;
		}
	}

	int f(int i) {
		int p = i;
		while (ids[p] != p)
			p = ids[p];

		while (ids[i] != i) {
			int pp = ids[i];
			ids[i] = p;
			i = pp;
		}

		return p;
	}

	void u(int i, int j) {
		int p1 = f(i), p2 = f(j);
		if (p1 == p2) return;

		int nS = sizes[p1] + sizes[p2];

		if (sizes[p1] < sizes[p2]) {
			ids[p1] = p2;
		} else {
			ids[p2] = p1;
		}

		sizes[p1] = sizes[p2] = nS;
	}
} UnionFind;

void solve() {
    int n, m, k;
	cin >> n >> m >> k;

	loop(i,0,m) {
		int u,v; cin >> u >> v;
	}

	UnionFind uf(n);
	vector<array<int, 3>> ops(k);
	loop(i,0,k) {
		string s;
		int u, v;
		cin >> s >> u >> v;
		ops[i] = {s=="cut", --u, --v};
	}

	reverse(ops.begin(), ops.end());
	vec<bool> answers;
	for (auto a : ops) {
		if (a[0]) {
			// cut -> union
			uf.u(a[1], a[2]);
		} else {
			// ask
			bool c = uf.f(a[1]) == uf.f(a[2]);
			answers.push_back(c);
		}
	}

	auto it = answers.rbegin();
	while (it != answers.rend()) {
		cout << (*it ? "YES\n" : "NO\n");
		it++;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
