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
    int n; cin >> n;
	vec<pair<int,int>> v(n);
	loop(i,0,n) {
		int x;
		cin >> x;
		v[i] = { x, i };
	}

	sort(v.begin(), v.end());
	int rounds = 1;
	loop(i,1,n) {
		if (v[i].S < v[i-1].S) rounds++;
	}

	cout << rounds << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
