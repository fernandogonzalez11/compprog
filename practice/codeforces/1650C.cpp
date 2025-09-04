#include <bits/stdc++.h>
#include <unordered_map>

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
    int n, m;
	cin >> n >> m;

	unordered_map<int, int> wmap;

	vec<pair<int, int>> wx(m);
	loop(i,0,m) {
		cin >> wx[i].S >> wx[i].F;
		wmap[wx[i].S] = i+1;
	}

	sort(wx.begin(), wx.end());

	vec<pair<int, int>> xw_filter;
	loop(i,0,2*n) xw_filter.push_back({ wx[i].S, wx[i].F });

	sort(xw_filter.begin(), xw_filter.end());

	// loop(i,0,xw_filter.size()) cout << xw_filter[i].F << " " << xw_filter[i].S << "\n";

	m = xw_filter.size();

	int s = 0;
	for (auto a : xw_filter) s += a.S;

	cout << s << "\n";

	for (int i = 0; i < xw_filter.size() / 2; i++)
		cout << wmap[xw_filter[i].F] << " " << wmap[xw_filter[(m-1)-i].F] <<  "\n";

	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
