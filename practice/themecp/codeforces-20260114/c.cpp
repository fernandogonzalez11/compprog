#include <bits/stdc++.h>
#include <cassert>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
	for (auto x : a) cout << x << " "; \
	cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
	int n,k;
	cin>>n>>k;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	map<int,int> m;
	loop(i,0,n) m[v[i]]++;

	for (auto &[_, v] : m) {
		if (v % k != 0) {
			cout << 0 << "\n";
			return;
		}

		v /= k;
	}

	int cnt = 0;

	int r = 0, l = 0, pastr = -1;
	for (; r < n; r++) {
		// consume
		if (--m[v[r]] < 0) {
			int elems = r-l;
			cnt += (elems)*(elems+1)/2;

			// cout << l << " " << r << " " << pastr << "\n";

			if (pastr != -1 && l <= pastr-1) {
				elems = pastr - l;
				assert(elems >= 0);
				cnt -= (elems)*(elems+1)/2;
			}

			while (m[v[r]] < 0) {
				++m[v[l++]];
			}

			pastr = r;

			// once done add a good one that's left
			// cnt++;
		}

		assert(l <= r);
	}

	int elems = r-l;
	cnt += (elems)*(elems+1)/2;

	// cout << l << " " << r << " " << pastr << "\n";

	if (pastr != -1 && l <= pastr-1) {
		elems = pastr - l;
		assert(elems >= 0);
		cnt -= (elems)*(elems+1)/2;
	}

	cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
