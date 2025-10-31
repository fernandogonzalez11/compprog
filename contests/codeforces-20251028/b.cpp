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
    array<int,30> lets;
	fill(lets.begin(), lets.end(), 0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	loop(i,0,n) {
		lets[s[i]-'a']++;
	}

	cin >> s;


	loop(i,0,n) {
		lets[s[i]-'a']--;
	}

	loop(i,0,lets.size()) {
		if (lets[i] != 0) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
