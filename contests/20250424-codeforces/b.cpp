#include <bits/stdc++.h>

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

void solve() {
    int n, x; cin >> n >> x;

	int cnt = 0;
	loop(i, 0, n) {
		if (i != x) {
			cout << i << " ";
			cnt++;
		}
	}
	
	if (cnt < n) cout << x << "\n";
	else cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
