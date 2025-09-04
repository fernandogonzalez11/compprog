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

vec<int> v;

bool ok(int x) {
	int n = v.size();
	deque<int> v_d(v.begin(), v.end());

	// rounds:
	loop(i,1,x+1) {
		// alice plays
		if (v_d.empty()) return false;

		bool picked = false;
		while (!v_d.empty()) {
			int a = v_d.back();
			v_d.pop_back();
			if (a <= x-i+1) {
				picked = true;
				break;
			}
		}
		if (!picked) return false;

		// bob plays
		if (!v_d.empty()) v_d.pop_front();

		// cout << "v_d: ";
		// for (auto it = v_d.begin(); it < v_d.end(); it++)
		// 	cout << *it << " ";
		// cout << "\n";
	}

	return true;
}

void solve() {
    int n;
	cin >> n;

	v.clear();
	v.resize(n);
	loop(i,0,n) cin >> v[i];

	sort(v.begin(), v.end());

	// loop(i,0,v.size()+2) cout << ok(i);
	// cout << "\n";

	int l = 0, r = n+1;
	while (r-l>1) {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	cout << l << "\n";

	// cout << ok(5) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
