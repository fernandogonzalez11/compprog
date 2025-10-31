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
    int x,y;
	cin >> x >> y;
	
	if (x==2 || y%2==1) {
		cout << "-1\n";
		return;
	}
	
	if (x<y) {
		if (x%2) cout << "-1\n";
		else cout << "2\n";
	} else {
		if (x%2) {
			// 1 -> y -> x-1
			if (1<y && (x-1)>y) cout << "3\n";
			else cout << "-1\n";
		} else {
			// 1 ->
			if (1<y && 3<y && )
		}
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
