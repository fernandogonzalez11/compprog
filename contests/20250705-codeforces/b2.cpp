#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

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
	double px, py, qx, qy;
	cin >> n >> px >> py >> qx >> qy;

	vec<double> a(n);
	double S = 0;
	double M = 0;
	loop(i,0,n) {
		cin >> a[i];
		S += a[i];
		M = max(M, a[i]);
	}

	double D = sqrt((px-qx)*(px-qx) + (py-qy)*(py-qy));

	if (S < D) return false;
	return (D >= max(2*M-S, 0.0));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "Yes\n" : "No\n");

	return 0;
}
