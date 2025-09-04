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
    // no derangements: good
	// 1+ derangement: whether we can solve all other derangements like that (yes)
	// and whether we wont create more

	int n; cin >> n;
	vec<int> v(n);
	loop(i,0,n) {
		cin >> v[i];
	}

	vec<int> v2 = v;

	bool fullySorted = true;
	loop(i,1,n) {
		if (v[i] < v[i-1]) fullySorted = false;
	}

	if (fullySorted) cout << "NO\n";
	else {
		
		sort(v2.begin(), v2.end());

		vec<int> res;
		loop(i,0,n) {
			if (v[i] == v2[i]) continue;
			else res.push_back(v[i]);
		}

		if (res.size() == 0) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << res.size() << "\n";
			loop(i,0,res.size()) cout << res[i] << " ";
			cout << "\n";
		}
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
