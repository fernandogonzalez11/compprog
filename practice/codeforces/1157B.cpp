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

void printnum(string &s) {
	for (char c : s) cout << c;
	cout << "\n";
}

void solve() {
    int n;
	cin >> n;
	string s;
	cin >> s;

	vec<int> t(10);
	loop(i,1,10) cin >> t[i];

	int i = 0;
	for (; i < n; i++) {
		if (t[s[i]-'0'] > s[i]-'0') break;
	}

	// cout << i << "\n";

	if (i == n) printnum(s);
	else {
		for (; i < n; i++) {
			if (t[s[i]-'0'] < s[i]-'0') break;
			s[i] = '0'+t[s[i]-'0'];
		}

		printnum(s);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
