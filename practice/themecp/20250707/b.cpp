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

int solve() {
    string s;
	cin >> s;

	int n = s.length();

	int firstOne = 0;
	while (firstOne < n && s[firstOne] == '0') firstOne++;
	if (firstOne == n) return 0;

	// cout << firstOne << "\n";

	int cost = 0;
	loop(i,firstOne+1,n) {
		if (s[i] == '1') {}
		else {
			cost += i - firstOne++ + 1;
			// cout << i << " c:" << cost << "\n";
		}
	}

	return cost;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}
