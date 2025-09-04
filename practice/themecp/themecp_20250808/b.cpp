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

vec<int> v;

int resolve(int upto, int x) {
	int n = v.size();
	if (upto < 0) return x > 1 ? INF : 0;

	int newX = gcd(x,v[upto]);

	int r = resolve(upto-1, x); // not choose
	if (newX != x) r = min(r, resolve(upto-1,newX) + (n - (upto+1) + 1)); // choose => drop some number of factors

	return r;
}

void solve() {
	v.clear();

    int n;
	cin >> n;

	v.resize(n);

	loop(i,0,n) cin >> v[i];

	int g = v[0];
	loop(i,1,n) g = gcd(g, v[i]);

	loop(i,0,n) v[i] = gcd(v[i], i+1);

	int cost = resolve(n-1, g);

	cout << cost << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
