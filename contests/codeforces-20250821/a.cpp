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
    int n, m;
	string a,b,c;
	cin >> n >> a >> m >> b >> c;

	deque<char> d(a.begin(), a.end());
	
	loop(k,0,c.size()) {
		if (c[k] == 'D') d.push_back(b[k]);
		else d.push_front(b[k]);
	}

	string f(d.begin(), d.end());
	cout << f << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
