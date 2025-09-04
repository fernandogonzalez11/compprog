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
    int x,y; cin >> y >> x;
	int m = max(x,y);

	int r = (m-1) * (m-1), offset = y + (m - x);
	if (m % 2 != 0) offset = (2*m - 1) - offset + 1;
	
	cout << r + offset << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
