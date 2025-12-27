#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

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

// Source - https://stackoverflow.com/a
// Posted by Captain Obvlious
// Retrieved 2025-11-16, License - CC BY-SA 3.0

struct UnionFind {
	int *ids, *sizes, *maxes;

	UnionFind(int n, vector<int> &v) {
		ids = new int[n];
		sizes = new int[n];
        maxes = new int[n];

		for (int i = 0; i < n; i++) {
			ids[i] = i;
			sizes[i] = 1;
            maxes[i] = v[i];
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
        int M = max(maxes[p1], maxes[p2]);

		if (sizes[p1] < sizes[p2]) {
			ids[p1] = p2;
		} else {
			ids[p2] = p1;
		}

		sizes[p1] = sizes[p2] = nS;
        maxes[p1] = maxes[p2] = M;
	}
};


void solve() {
    int n;
    cin >> n;

    vec<int> v(n);
    loop(i,0,n) cin >> v[i];

    priority_queue<pair<int,int>> q;
    loop(i,0,n) q.push({v[i],i});

    UnionFind uf(n, v);
    int cost = 0;
    // O(n log n) (priority queue)
    loop(_,0,n-1) {
        int x,j;
        tie(x,j) = q.top();
        q.pop();

        int grp1 = uf.f((j+1)%n),
            grp2 = uf.f((j-1+n)%n);

        if (uf.maxes[grp1] < uf.maxes[grp2]) {
            uf.u(j, grp1);
            cost += uf.maxes[grp1];
        } else {
            uf.u(j, grp2);
            cost += uf.maxes[grp2];
        }
    }

    cout << cost << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
