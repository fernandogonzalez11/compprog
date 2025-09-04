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

using namespace std;

void solve() {
	int n;
	cin >> n;
	vec<int> v(n);
	map<int, vec<int>> m;
	loop(i,0,n) {
		cin >> v[i];
		m[v[i]].push_back(i);
	}

	int cnt = 0;
	while (true) {
		int mmin = INF;
		int allEmpty = true;
		for (auto &a : m) {
			if (!a.S.empty()) {
				allEmpty = false;
				mmin = min(mmin, a.S[a.S.size()-1]);
				a.S.pop_back();
			}
		}

		if (allEmpty) break;

		// for (auto &a : m) {
		// 	while (!a.S.empty() && a.S[a.S.size()-1] >= mmin)
		// 		a.S.pop_back();
		// }

		cnt++;
	}

	cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
