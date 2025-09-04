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
	vec<int> v1(n), v2(n);
	loop(i,0,n) cin >> v1[i];
	loop(i,0,n) cin >> v2[i];

	loop(i,0,n-1) 
		if (v1[i] != v2[i]) v1[i] ^= v1[i+1];

	loop(i,0,n) 
		if (v1[i] != v2[i]) return false;
	
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n": "NO\n");

	return 0;
}
