#include <algorithm>
#include <bits/stdc++.h>

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
	int n;
	cin>>n;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	vec<pii> p(n);
	loop(i,0,n) p[i] = {v[i], i};

	int maxelegible = 0;
	loop(i,0,n) {
		bool elegible = false;
		if (i > 0) elegible |= v[i]<v[i-1];
		if (i < n-1) elegible |= v[i]<v[i+1];
		if (elegible) maxelegible = max(maxelegible, v[i]);
	}

	map<int, int> m;
	loop(i,0,n) {
		if (!m.count(v[i])) m[v[i]] = i;
		else {
			int dist = i-m[v[i]];
			if (dist<=2) maxelegible = max(maxelegible, v[i]);
			m[v[i]] = i;
		}
	}

	cout << maxelegible << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
