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

int s = 0, x, y, n;
vec<int> v;

void solve() {
	cin >> n >> x >> y;

	v.resize(n);
	loop(i,0,n) {
		cin >> v[i];
		s += v[i];
	}

	sort(v.begin(), v.end());

	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
