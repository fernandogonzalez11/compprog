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

	vec<int> a(n), b(n);

	loop(i,0,n) cin >> a[i];
	loop(i,0,n) cin >> b[i];

	int iter = 0;
	while (true) {
		iter++;
		// step 1
		bool did = false;
		loop(i,0,n) {
			if (a[i] > b[i]) {
				a[i]--;
				did = true;
				break;
			}
		}

		if (!did) break;

		loop(i,0,n) {
			if (a[i] < b[i]) {
				a[i]++;
			}
		}
	}

	cout << iter << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
