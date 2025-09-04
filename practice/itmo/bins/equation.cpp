#include <bits/stdc++.h>
#include <iomanip>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

double c;

bool ok(double x) {
	return (x * x + sqrt(x)) < c;
}

double binsearch() {
	double l = 0, r = 1e11;
	loop(i,0,100) {
		double m = (r-l)/2+l;
		// cout << l << " "  << r <<  " " << m << " " << ok(m) << "\n";
		if (ok(m)) l = m;
		else r = m;
	}

	return l;
}

void solve() {
    cin >> c;
	cout << setprecision(10) << binsearch();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
