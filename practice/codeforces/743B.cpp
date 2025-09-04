#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
	k--;

	// start at middle: will hold n
	int s = ((1LL << n) - 1) / 2;

	while (true) {
		if (s == k) {
			cout << n << "\n";
			break;
		} else if (s < k) {
			// jump 2^(n-2) right
			s += (1LL << (n-2));
			n--;
		} else {
			// jump n-1 left
			s -= (1LL << (n-2));
			n--;
		}
	}
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
