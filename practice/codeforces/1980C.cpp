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

bool solve() {
    int n;
	cin >> n;
	vec<int> a(n), b(n);
	loop(i,0,n) cin >> a[i];
	loop(i,0,n) cin >> b[i];

	int m;
	cin >> m;
	vec<int> o(m);
	loop(i,0,m) cin >> o[i];

	vector<int> trans;
	loop(i,0,n)
		if (a[i] != b[i]) trans.push_back(b[i]);

	// no way
	if (o.size() < trans.size()) return false;

	if (trans.empty()) {
		// no transitions must be done
		// -> all ops are ops that shouldnt change
		// ops that shouldnt change -> check if the last element of the ops is in array b

		for (int e : b)
			if (o[m-1] == e) return true;

		return false;
	} else {
		// i should find all needed transformations in ops
		{	
			unordered_set<int> oSet;
			loop(i,0,m) oSet.insert(o[i]);
			loop(i,0,trans.size())
				if (!oSet.count(trans[i])) return false;
		}

		// ops that shouldnt change -> check if the last element of the ops is in array b
		// if no ops that shouldnt change -> true
			// if last op is a trans

		for (int t : trans)
			if (o[m-1] == t) return true;

		for (int e : b)
			if (o[m-1] == e) return true;

		return false;
	}

	// ops that transform a to b
	// ....
	// ops that shouldnt change -> check if the last element of the ops is in array b
	// ....
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
