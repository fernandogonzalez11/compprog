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

9
6
1 3 4 5 2 6
4
3 4 1 2
5
4 3 5 1 2
4
1 2 3 4
7
4 3 5 7 6 2 1
6
2 4 6 1 3 5
3
2 1 3
4
2 4 1 3
6
4 2 6 5 1 3


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
