#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
	loop(i,0,k) cout << 1;
	loop(i,0,n-k) cout << 0;
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
