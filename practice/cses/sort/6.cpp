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
    int n;
	cin >> n;

	vec<pair<int, int>> mubi(n);
	loop(i,0,n) cin >> mubi[i].S >> mubi[i].F;

	sort(mubi.begin(), mubi.end());

	int t = 0;
	int cnt = 0;
	loop(i,0,n) {
		auto p = mubi[i];
		int start = p.S, end = p.F;
		if (t <= start) {
			cnt++;
			t = end;
		}
	}

	cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
