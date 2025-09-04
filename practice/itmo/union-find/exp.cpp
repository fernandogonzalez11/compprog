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
	int *ids, *sizes, *exps;
	int n;

	uf(int nn) {
		n = nn;
		ids = new int[n];
		sizes = new int[n];
		exps = new int[n];

		for (int i = 0; i < n; i++) {
			ids[i] = i;
			sizes[i] = 1;
			exps[i] = 0;
		}
	}

	int f(int i) {
		int p = i;
		while (ids[p] != p)
			p = ids[p];

		// no path compression: O(log n)
		// while (ids[i] != i) {
		// 	int pp = ids[i];
		// 	ids[i] = p;
		// 	i = pp;
		// }

		return p;
	}

	void u(int i, int j) {
		int p1 = f(i), p2 = f(j);
		if (p1 == p2) return;		

		int nS = sizes[p1] + sizes[p2];

		if (sizes[p1] < sizes[p2]) {
			// join p1 to p2
			ids[p1] = p2;
			exps[p1] -= exps[p2];
		} else {
			// join p2 to p1
			ids[p2] = p1;
			exps[p2] -= exps[p1];
		}

		sizes[p1] = sizes[p2] = nS;
	}

	// O(log n)
	void add(int i, int amt) {
		i = f(i);
		exps[i] += amt;
	}

	// O(log n)
	int get(int i) {
		int s = 0;
		while (ids[i] != i) {
			s += exps[i];
			i = ids[i];
		}

		s += exps[i];

		return s;
	}
} UnionFind;

void solve() {
    int n,m;
	cin >> n >> m;

	UnionFind uf(n);
	loop(i,0,m) {
		string s;
		cin >> s;

		if (s == "add") {
			int a, amt;
			cin >> a >> amt;

			uf.add(--a, amt);
		} else if (s == "join") {
			int a, b;
			cin >> a >> b;

			uf.u(--a,--b);
		} else {
			int a;
			cin >> a;

			cout << uf.get(--a) << "\n";
		}
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
