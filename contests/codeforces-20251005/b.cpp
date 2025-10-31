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
    int n, k;
	cin >> n >> k;

	if (k == n*n-1) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	if (k == 1 && n == 2) {
		cout << "LD\nRL\n";
		return;
	}

	bool splitLast = (k % n == n-1);
	
	int full = k / n;
	loop(i,0,full) {
		loop(j,0,n) cout << "L";
		cout << "\n";
	}

	if (k == n*n) return;

	if (splitLast) {
		int rest = k%n;
		loop(i,0,rest-1) cout << "L";
		cout << "R";
		loop(i,0,n-(rest-1)-1) cout << "L";
		cout << "\n";

		cout << "L";
		cout << "R";
		loop(i,0,n-2) cout << "L";
		cout << "\n";

		loop(i,0,n-full-2) {
			cout << "R";
			loop(j,0,n-1) cout << "L";
			cout << "\n";
		}
	} else {
		int rest = k%n;
		loop(i,0,rest) cout << "L";
		cout << "R";
		loop(i,0,n-rest-1) cout << "L";		
		cout << "\n";

		loop(i,0,n-full-1) {
			cout << "R";
			loop(j,0,n-1) cout << "L";
			cout << "\n";
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
