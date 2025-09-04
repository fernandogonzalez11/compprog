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
    /*
	cant have 0
	should start with 1 / -1

	-1 3 -1 3 .... -1 2?
	*/

	int n;
	cin >> n;

	int ns[n];
	{
		int i = 0;
		while (i < n) {
			ns[i++] = -1;
			if (i < n) ns[i++] = 3;
		}

		if (n % 2 == 0) ns[n-1] = 2;
	}

	loop(i,0,n) cout << ns[i] << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
