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
    string n, s; cin  >> n >> s;
	int cnt = 0;
	for (char c : s)
		cnt += (c == '1');

	int tot = 0;
	for (char c : s) {
		// +1 for 0 flip to 1
		int b = 1;
		if (c == '1') b = -1;
		tot += cnt + b;
	}
	
	cout << tot << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
