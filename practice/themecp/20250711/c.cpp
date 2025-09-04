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

bool solve() {
    int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;

	loop(i,-1,n) {
		char c = i == -1 ? 'L' : s[i];

		// cout << i << " " << c << "\n";

		if (c == 'C') return false;
		else if (c == 'W') {
			k--;
			if (k == -1) return false;
		} else if (c == 'L') {
			if (i + m >= n) return true;
			int highestL = -1, highestW = -1;
			for (int j = i+m; j > i; j--) {
				if (s[j] == 'L' && highestL == -1) highestL = j;
				else if (s[j] == 'W' && highestW == -1) highestW = j;
			}
			if (highestL == -1 && highestW == -1) return false;
			if (highestL == -1) {
				i = highestW;
				i--;
			} else {
				i = highestL;
				i--;
			}
		}
	}

	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
