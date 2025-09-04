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

int n, k;

// amt of elems that are < x
// min x is 1
int calc(int x) {
	int s = 0;

	int i;
	if (x > n) i = n;
	else i = x - 1;
	
	while (i > 0) {
		s += min(n, (int) (ceil((double) x / i) - 1));
		i--;
	}

	return s;
}

bool ok(int x) {
	return calc(x) <= k;
}

void solve() {
	cin >> n >> k;
	k--;

	int l = 1, r = n*n+1;

	// loop(i,l,r+1) cout << i << " " << calc(i) << " " <<  ok(i)<< "\n";

	while (r-l>1) {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	cout << l << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
