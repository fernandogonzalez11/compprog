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
    int n,m;
	cin >> n >> m;

	UnionFind uf(n);
	loop(i,0,m) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		a--; b--;

		if (s == "union") {
			uf.u(a, b);
		} else {
			bool is = uf.f(a) == uf.f(b);
			cout << (is ? "YES\n" : "NO\n");
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
