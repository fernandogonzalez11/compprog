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

	int aw, ab, bw, bb;
	aw=ab=bw=bb=0;

	aw += 1;
	n--;

	int i = 2;
	while (n > 0) {
		// bob
		int s = min(n, i + i + 1);
		bw += s/2;
		bb += s-s/2;

		n -= s;

		// alice
		i += 2;
		s = min(n, i + i + 1);
		aw += s-s/2;
		ab += s/2;

		n -= s;

		i += 2;
	}

	cout << aw << " " << ab << " " << bw << " " << bb << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
