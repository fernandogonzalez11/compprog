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

	int f(int a) {
		int p = a;
		while (ids[p] != p) {
			p = ids[p];
		}

		while (ids[a] != a) {
			int prev = ids[a];
			ids[a] = p;
			a = prev;
		}

		return p;
	}

	void u(int a, int b) {
		int p1 = f(a), p2 = f(b);
		if (p1 == p2) return;

		int s = sizes[p1] + sizes[p2];

		if (sizes[p1] < sizes[p2]) {
			ids[p1] = p2;
		} else {
			ids[p2] = p1;
		}

		sizes[p1] = sizes[p2] = s;
	}
} UnionFind;

void solve() {
    
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
