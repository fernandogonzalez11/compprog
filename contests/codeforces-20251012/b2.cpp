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
#define printarr(a) /*cout << #a << ": ";*/ \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
    int n;
	cin >> n;
	vec<int> b(n), a(n, -1);
	multimap<int, int> freq2ai;

	loop(i,0,n) cin >> b[i];

	a[0] = 1;
	freq2ai.insert({1, 1});

	int put = 2;

	loop(i,1,n) {
		int increase = b[i] - b[i-1];
		// increase is now contribution from [0, i-1]
		increase--;

		// int nondistinct = i - increase;

		// // all are distinct: new number
		// if (nondistinct == 0) {
		// 	a[i] = put++;
		// 	freq2ai.insert({1, a[i]});
		// } else {
		// 	// some other number has to have this exact amount of current occurrences
		// 	auto p = freq2ai.find(nondistinct);
		// 	a[i] = p->second;
		// 	// update the map with new frequencies
		// 	freq2ai.insert({ p->first+1, p->second });
		// 	freq2ai.erase(p);
		// }

		if (increase == 0) a[i] = a[i-1];
		else if (increase == i) a[i] = put++;
		else a[i] = a.at(i-increase-1);
	}

	printarr(a);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
