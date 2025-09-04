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
	// cout << "2 ";
	// loop(i,0,n-3) cout << "1 ";
	// cout << "2 1" << "\n";

	cout << "1 ";
	loop(i,0,n-1) cout << i%3+1 << " ";
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
