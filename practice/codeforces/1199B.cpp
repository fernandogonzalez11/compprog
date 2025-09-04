#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void solve() {
    double h, l; cin >> h >> l;
	double r = (l*l - h*h) / (2*h);

	cout << setprecision(14) << r << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t = 1;// cin >> t;
    while (t--) solve();

	return 0;
}
