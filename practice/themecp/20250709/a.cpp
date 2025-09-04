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

	int firstB = 0, lastB = n-1;

	while (firstB < n && s[firstB] != 'B') firstB++;
	while (lastB >= 0 && s[lastB] != 'B') lastB--;

	int dist = max(0LL, lastB - firstB + 1);
	cout << dist << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
