#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

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
    // obs: 0 -> always 1
	// obs: 0 0 1 1 3 4 5 mex is 2, we shouldnt be removing 3 4 5 bc they dont
	// change anything ever
	
	int n;
	cin >> n;
	vec<int> a(n);
	loop(i,0,n) cin >> a[i];

	unordered_multiset<int> amts;
	loop(i,0,n) amts.insert(a[i]);

	int mex = 0;
	while (amts.count(mex) > 0) mex++;

	// cout << mex << "\n";

	// cnt, #
	vec<int> v;
	loop(i,0,mex)
		if (amts.count(i)) v.push_back(amts.count(i));

	sort(v.begin(), v.end());

	loop(i,0,n) cout << v[i] << " "; cout << "\n";

	loop(i,0,n) {
		int obt = upper_bound(v.begin(), v.end(), i) - 1 - v.begin();
		
		if (obt == -1) cout << 1 << " ";
		else cout << 1 + obt*(obt-1)/2 << " ";
	}
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
