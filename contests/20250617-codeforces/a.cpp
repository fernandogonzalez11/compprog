#include <algorithm>
#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

void solve() {
    int n, s;
	cin >> n >> s;
	vec<int> v(n);

	loop(i,0,n) cin >> v[i];
	int m = *min_element(v.begin(), v.end());
	int M = *max_element(v.begin(), v.end());

	if (s <= m) {
		cout << M - s << "\n";
	} else if (s >= M) {
		cout << s - m << "\n";
	} else {
		int mm = min(s - m, M - s);
		int MM = max(s - m, M - s);

		cout << (mm * 2) + MM << "\n";
	}

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
