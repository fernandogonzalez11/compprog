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
    int n;
	cin >> n;
	vec<int> p(n), idxs(n+1);
	loop(i,0,n) {
		cin >> p[i];
		idxs[p[i]] = i;
	}

	// make prefs of idxs
	vec<int> minPref(n+1), maxSuf(n+1);
	minPref[1] = idxs[1];
	loop(i,2,n+1) minPref[i] = min(minPref[i-1], idxs[i]);

	maxSuf[n] = idxs[n];
	for (int i = n-1; i > 0; i--) maxSuf[i] = max(maxSuf[i+1], idxs[i]);

	bool h = false;
	// loop in order of permutation to maintain order relation
	loop(i,1,n)
		// if not even the min up to that point can connect
		// the max, theres no hope with that number
		// connecting with shi
		h |= (minPref[i] > maxSuf[i+1]);

	cout << ((!h)?"Yes\n":"No\n");
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
