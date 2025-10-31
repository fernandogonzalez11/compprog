#include <bits/stdc++.h>
#include <cstdio>

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
    int m, n, k;
	cin >> m >> n >> k;

	loop(i,0,m) {
		string s;
		getline(cin >> ws, s);
		loop(t1,0,k) {// row repetitions
			loop(j,0,n) // for each character
				loop(t2,0,k) // column repetitions
					cout << s[j];

			cout << "\n";
		}
	}
}

signed main() {
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
