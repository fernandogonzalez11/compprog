#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

void solve() {
    int n;
	cin >> n;

	int tot = (n-2+1) + (n-2-1+1);
	cout << tot << "\n";

	for (int i = 2; i <= n; i++)
		cout << i << " " << 1 << " " << i << "\n";

	for (int i = 1; i <= n-2; i++)
		cout << i << " " << i+1 << " " << n << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
