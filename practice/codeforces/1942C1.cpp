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
    int n, x, y;
	cin >> n >> x >> y;

	vec<int> v(x);
	loop(i,0,x) cin >> v[i];
	sort(v.begin(), v.end());

	int trng = max(0LL, (int) x - 2);
	loop(i,0,x-1)
		trng += (((v[i]-1 + 2) % n) == v[i+1]-1);
	trng += (((v[x-1]-1 + 2) % n) == v[0]-1);

	cout << trng << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
