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

	string s;
	cin >> s;

	vec<int> scpref(n), scsuf(n);
	vec<bool> vis(26, 0);
	scpref[0] = scsuf[n-1] = 1;
	vis[s[0]-'a'] = true;
	for (int i = 1; i < n; i++) {
		scpref[i] = scpref[i-1];
		if (!vis[s[i]-'a']) {
			vis[s[i]-'a'] = true;
			scpref[i]++;
		}
	}

	fill(vis.begin(),vis.end(),0);
	vis[s[n-1]-'a'] = true;
	for (int i = n-2; i >= 0; i--) {
		scsuf[i] = scsuf[i+1];
		if (!vis[s[i]-'a']) {
			vis[s[i]-'a'] = true;
			scsuf[i]++;
		}
	}

	// printarr(scpref);
	// printarr(scsuf);

	int m = max(scpref[n-1], scsuf[0]);
	for (int i = 0; i < n-1; i++) {
		m = max(m, scpref[i] + scsuf[i+1]);
	}
	cout << m << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
