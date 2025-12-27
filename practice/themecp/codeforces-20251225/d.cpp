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

void solve() {
    int n,k;
	cin>>n>>k;

	vec<int> a(n),h(n);
	loop(i,0,n) cin>>a[i];
	loop(i,0,n) cin>>h[i];

	// reverse(a.begin(),a.end());
	// reverse(h.begin(),h.end());

	vec<int> segments = {0};
	loop(i,0,n-1) {
		if (h[i]%h[i+1] != 0) segments.push_back(i+1);
	}
	segments.push_back(n);

	// printarr(segments);

	int m = 0;
	loop(i,0,segments.size()-1) {
		int L = segments[i], R = segments[i+1]-1, s = 0;

		int l = L, r = L;

		while (r <= R) {
			if (s > k) {
				s -= a.at(l++);
			} else {
				m = max(m, r-l);
				s += a.at(r++);
			}
			// cout << l << " " << r << "\n";
		}
		if (s <= k) m = max(m, r-l);
	}

	cout << m << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
