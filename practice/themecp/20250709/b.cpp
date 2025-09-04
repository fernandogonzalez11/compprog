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

void op(int center) {
	v[center] -= 2 * v[center - 1];
	v[center + 1] -= v[center - 1];
	v[center - 1] = 0;
	// printarr(v);
}

bool solve() {
    int n;
	cin >> n;
	v.resize(n);
	loop(i,0,n) cin >> v[i];

	loop(i,0,n-2) {
		if (v[i] > 0) {
			op(i+1);
			if (v[i+1] < 0 || v[i+2] < 0) return false;
		}
	}

	return v[n-1] == 0 && v[n-2] == 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
