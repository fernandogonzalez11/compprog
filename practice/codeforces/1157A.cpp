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

int f(int n) {
	while (n%10 == 0) n /= 10;
	return n;
}

void solve() {
    int n;
	cin >> n;
	int cnt = 9;
	while (n >= 10) {
		cnt += (9 - n%10 + 1);
		n += 10 - n%10;
		n = f(n);
		// cout << n << "\n";
	}
	cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
