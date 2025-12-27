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
    int x,n;
	cin >> x >> n;

	if (n==1) {cout << x << "\n"; return;}

	int g = 1;
	for (int i = 2; i * i <= x; i++) {
		if (x%i != 0) continue;
		int div1 = i, div2 = x/i;
		if (x/div1 >= n) g = max(g, div1);
		if (x/div2 >= n) g = max(g, div2);
	}

	cout << g << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
