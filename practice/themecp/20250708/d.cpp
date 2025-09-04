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

bool solve() {
    int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	for (int i = 1; i < n; i += 2) v[i] = -v[i];

	vec<int> pref(n+1);
	pref[0] = 0;
	loop(i,0,n) pref[i+1] = pref[i] + v[i];

	// printarr(pref);

	set<int> s;
	loop(i,0,n+1) {
		if (s.count(pref[i])) return true;
		s.insert(pref[i]);
	}

	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
