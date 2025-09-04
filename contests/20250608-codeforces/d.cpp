#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 63)
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	loop(i,0,n) v[i] = v[i] - (n+1-(i+1));
	loop(i,0,n) cout << v[i] << " ";
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
