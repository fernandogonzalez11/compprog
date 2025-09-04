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

const int MOD = 998244353LL;

int n,m;
vec<pair<int,int>> segs;
vec<pair<int,int>> probs;
vec<int> idx;

typedef struct b {
	int searching;
	int n;
	vec<bool> subset;

	b(int nn) {
		n = nn;
		subset.resize(n);
	}
} b;

pair<int, int> pqify(vec<bool> subset) {
	int p = 1;
	int q = 1;
	loop(i,0,n) {
		if (subset[i]) {
			p *= probs[i].F;
		} else {
			p *= probs[i].S - probs[i].F;
		}
		p %= MOD;

		q *= probs[i].S;
		q %= MOD;
	}

	return {p,q};
}

int ok(int m, int x) {
	return segs[idx[m]].F <= x;
}

void solve() {
	cin >> n >> m;
	segs.resize(n);
	probs.resize(n);
	idx.resize(n);

	loop(i,0,n) {
		cin >> segs[i].F >> segs[i].S >> probs[i].F >> probs[i].S;
		idx[i] = i;
	}

	sort(idx.begin(), idx.end(), [&](int i, int j) {
		return segs[i] < segs[j];
	});

	int P = 1;
	int Q = 1;

	queue<b> q;
	for (int i : idx) {
		if (segs[i].F != 1) break;
		b bb = b(n);
		bb.searching = segs[i].S + 1;
		bb.subset[i] = true;
		q.push(bb);
	}

	while (!q.empty()) {
		b bb = q.front();
		q.pop();

		if (bb.searching > m) {
			auto p = pqify(bb.subset);
			P *= p.F;
			P %= MOD;
			Q *= p.S;
			Q %= MOD;
		} else {
			// find searching
			int l = 0, r = n-1;
			while (r - l > 1) {
				int m = (r-l)/2+l;
				if (ok(m, bb.searching)) l = m;
				else r = m;
			}

			if (segs[idx[l]].F != bb.searching) l = r;
			if (segs[idx[l]].F != bb.searching) continue;
			loop(i,l,n) {
				if (segs[idx[i]].F != bb.searching) break;
				b bb = b(n);
				bb.searching = segs[idx[i]].S + 1;
				bb.subset[idx[i]] = true;
				q.push(bb);
			}
		}
	}

	// TODO: MODULAR INV
	cout << P << " " << Q << "\n";
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
