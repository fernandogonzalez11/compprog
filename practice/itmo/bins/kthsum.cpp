#include <algorithm>
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
vec<int> a, b;

// amt of nums which are < x
// for each num in a, binsearch the last one in b s.t. a[i] + b[i] < x
// => b[i] < x - a[i]
// lower_bound: first b[i] >= x - a[i]
// lower_bound - 1: last b[i] < x - a[i]
int calc(int x) {
	int amt = 0;

	for (int num : a) {
		// can't sum up to x this way
		if (num >= x) continue;
		
		// guaranteed to search for at least value 1
		int lcl_amt = lower_bound(b.begin(), b.end(), x - num) - b.begin();

		amt += max(0LL, lcl_amt);
	}

	return amt;
}

bool ok(int x) {
	return calc(x) <= k;
}

void solve() {
	cin >> n >> k;
	k--;
	a.resize(n);
	b.resize(n);

	loop(i,0,n) cin >> a[i];
	loop(i,0,n) cin >> b[i];

	sort(b.begin(), b.end());

	// loop(i,0,15) cout << calc(i) << " ";

	// VVVVVFFF
	int l = 2, r = 3;
	while (ok(r)) r *= 2;

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
