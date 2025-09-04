#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

void solve() {
    int a,b,p;
	cin >> a >> b >> p;
	string s;
	cin >> s;

	int n = s.size();

	vec<int> cost(n);
	cost[n-1] = s[n-1] == 'A' ? a : b;

	int i = n-2;

	for (; i >= 0; i--) {
		if (s[i] == s[i+1]) cost[i] = cost[i+1];
		else cost[i] = (i != n-2 ? cost[i+1] : 0) + (s[i] == 'A' ? a : b);

		if (cost[i] > p) {
			// cout << "term " << cost[i] << "\n";
			break;
		}
	}

	cout << ++i + 1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
