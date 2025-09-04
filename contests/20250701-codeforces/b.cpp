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

using namespace std;

bool solve() {
    int n, j, k;
	cin >> n >> j >> k;
	j--;

	vec<int> v(n);
	loop(i,0,n) cin >> v[i];
	if (k >= 2) return n == k || n-1 >= 2 || v[j] > v[n-j-1];
	else {
		int m = -1;
		loop(i,0,n)
			if (i != j)
				m = max(m, v[i]);

		return v[j] >= m;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// cout << INF << "\n";

	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
