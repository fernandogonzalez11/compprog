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

int bset(int x, int y, int i) {
	return x | (y<<i);
}

void solve() {
    int n;
	cin >> n;

	int x = (1<<n)-1;
	cout << x << " ";

	x = x & ~(1<<(n-1));
	cout << x << " ";
	
	for (int b = n-2; b >= 0; b--) {
		// unset bit b
		x = x & ~(1<<b);
		cout << x << " ";

		// try all nums with bits before it
		// [b+1, n-1]
		int bitamt = n-1 - (b+1) + 1;
		// cout << bitamt << "\n";

		for (int s = 1; s < (1<<(bitamt)); s++) {
			cout << bset(x, s, b+1) << " ";
		}
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
