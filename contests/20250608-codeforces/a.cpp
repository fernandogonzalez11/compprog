#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 63)
#define int long long

using namespace std;

bool solve() {
    int n,x; cin >> n >> x;
	vec<int> v(n); loop(i,0,n) cin >> v[i];

	int i = 0;
	while (i < n && !v[i]) i++;

	// cout << i << "\n";
	
	if (i == n) return true;

	i += x;
	if (i >= n) return true;

	while (i < n)
		if (v[i++]) return false;

	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << "\n";

	return 0;
}
