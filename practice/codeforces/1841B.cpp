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
    int q;
	cin >> q;

	int a(-1), b, c;

	// always put first
	cin >> b;
	c = b;
	cout << 1;
	q--;

	while (q--) {
		int y;
		cin >> y;
		// if havent found interrupt => add
		// if found less than => bounded by c <= x <= b

		if (a == -1) {
			if (y >= b) {
				b = y;
				cout << 1;
			} else {
				if (y > c) cout << 0;
				else {
					a = y;
					cout << 1;
				}
			}
			// cout << " " << a << " " << b << "\n";
		} else {
			if (a <= y && y <= c) {
				a = y;
				cout << 1;
			} else cout << 0;
		}
	}

	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
