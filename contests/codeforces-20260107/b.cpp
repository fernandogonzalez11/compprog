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
	int n,k;
	cin>>n>>k;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	sort(all(v));

	if (v[0] != 0) {
		cout << 0 << "\n";
		return;
	}

	vec<bool> rm(n, false);
	int sz = n;
	loop(i,1,n) {
		if (v[i]==v[i-1]) {
			rm[i] = true;
			sz--;
		}
	}

	if (sz > k-1) {
		for (int i = n-1; i >= 0; i--) {
			if (!rm[i]) {
				rm[i] = true;
				if (--sz <= k-1) break;
			}
		}
	}

	int mex = 0;
	loop(i,1,n) {
		if (rm[i]) continue;
		if (v[i]-mex > 1) {
			mex++;
			break;
		} else if (v[i]-mex == 1) mex++;
	}

	cout << ++mex << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
