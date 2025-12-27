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
    string s;
	cin >> s;
	int n = s.length();

	bool works = false;
	loop(i,0,n-1) {
		if (s[i]==s[i+1]) {
			cout << s[i] << s[i+1] << "\n";
			return;
		}
	}
	loop(i,0,n-2) {
		if (s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2]) {
			cout << s[i] << s[i+1] << s[i+2] << "\n";
			return;
		}
	}

	cout << "-1\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
