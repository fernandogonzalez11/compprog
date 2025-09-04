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

	vec<int> d(n);
	loop(i,0,n) cin >> d[i];

	vec<pair<int,int>> lr(n);
	loop(i,0,n) cin >> lr[i].F >> lr[i].S;

	int ifIIncrease = 0, ifIStay = 0;

	loop(i,0,n) {
		if (d[i] > 0) {
			ifIIncrease++;
			// no chance to stay in place
			ifIStay++;
		} else if (d[i] < 0) {
			ifIIncrease++;
			// chance to stay in place
		} else {
			// has to stay in place
		}

		if (ifIStay < lr[i].F) ifIStay = lr[i].F;
		if (ifIIncrease > lr[i].S) ifIIncrease = lr[i].S;

		// si no hay resquicio de verdad estamos mal
		if (ifIStay > ifIIncrease) {
			cout << "-1\n";
			return;
		}
	}

	cout << "how\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
