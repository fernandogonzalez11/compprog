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
    int n, m;
	cin >> n >> m;

	int a, b, in, s, pts;
	in = s = pts = 0;
	loop(i,0,n) {
		cin >> a >> b;
		int k = a-s;
		if (in == b) {
			pts += k - k%2;
		} else {
			pts++;
			k--;
			pts += k - k%2;
		}
		s = a;
		in = b;

		// cout << "u:" << pts << "\n";
	}

	pts += m-s;

	cout << pts << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
