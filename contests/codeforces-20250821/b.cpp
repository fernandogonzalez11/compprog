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
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
    int n;
	cin >> n;

	vec<int> ns;

	int i = 10;
	while (i+1 <= n) {
		if (n % (i+1) == 0) ns.push_back(n/(i+1));
		i *= 10;
	}

	reverse(ns.begin(), ns.end());
	cout << ns.size() << "\n";
	if (ns.size()) {
		for (int i : ns) cout << i << " ";
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
