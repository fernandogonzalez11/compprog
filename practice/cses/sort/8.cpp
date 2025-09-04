#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;

	int global_max = 0, local_max = 0;
	cin >> local_max;
	global_max = local_max;
	loop(i,1,n) {
		int x; cin >> x;
		local_max = max(local_max + x, x);
		global_max = max(local_max, global_max);
	}

	cout << global_max << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
