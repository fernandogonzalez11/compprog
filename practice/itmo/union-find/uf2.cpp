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
	int *ids, *sizes, *mins, *maxs;

	uf(int n) {
		ids = new int[n];
		sizes = new int[n];
		mins = new int[n];
		maxs = new int[n];
		for (int i = 0; i < n; i++) {
			ids[i] = mins[i] = maxs[i] = i;
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
		int nm = min(mins[p1], mins[p2]);
		int nM = max(maxs[p1], maxs[p2]);

		sizes[p1] = sizes[p2] = nS;
		mins[p1] = mins[p2] = nm;
		maxs[p1] = maxs[p2] = nM;

		if (sizes[p1] < sizes[p2]) {
			ids[p1] = p2;
		} else {
			ids[p2] = p1;
		}
	}
} UnionFind;

void solve() {
    int n,m;
	cin >> n >> m;

	UnionFind uf(n);
	loop(i,0,m) {
		string s;
		int a, b;
		cin >> s;
		
		if (s == "union") {
			cin >> a >> b;
			a--; b--;
			uf.u(a, b);
		} else {
			cin >> a;
			a--;
			int p = uf.f(a);

			cout << uf.mins[p]+1 << " "
				 << uf.maxs[p]+1 << " "
				 << uf.sizes[p] << "\n";
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
