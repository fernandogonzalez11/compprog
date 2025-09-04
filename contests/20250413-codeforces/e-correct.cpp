#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void proc() {
	int n; cin >> n;
	vec<ll> ns(n);
	
	loop(i, 0, n) cin >> ns[i];
	int tot_or = ns[0];
	loop(i, 1, n) tot_or |= ns[i];

	tot_or = ~tot_or & ~(1 << 31);

	cout << tot_or << "\n";
	// sort(ns.begin(), ns.end());


	// loop(i, 0, n) cout << ns[i] << " ";

	// ll m = -INF;

	// // cout << "\n";
	// for (ll e : ns) {
	// 	ll s = 0;
	// 	loop(i, 0, n) {
	// 		s += ns[i] ^ e;
	// 	}

	// 	m = max(m, s);
	// }
	// // cout << "\n";
	// cout << m << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
