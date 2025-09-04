#include <algorithm>
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
    int m, k;
	cin >> m >> k;

	vec<int> d(m);
	loop(i,0,m) cin >> d[i];

	vec<int> s(m);
	loop(i,0,m) cin >> s[i];

	vec<int> prefsS(m);
	vec<int> prefsD(m);
	prefsS[0] = s[0];
	prefsD[0] = d[0];

	vec<int> order;
	order.push_back(0);

	loop(i,1,m) {
		if (s[i] > s[order[order.size()-1]])
			order.push_back(i);

		prefsS[i] = prefsS[i-1] + s[i];
		prefsD[i] = prefsD[i-1] + d[i];
	}

	order.push_back(m);

	// loop(i,0,order.size()) cout << order[i] << " ";
	// cout << "\n";

	int f = 0;
	int t = 0;
	loop(i, 0, order.size() - 1) {
		int l = order[i], r = order[i+1] - 1;

		// cout << "to do " << l << " to " << r << "\n";

		// sum s from l to r
		int cover = prefsD[r] - (l ? prefsD[l-1] : 0);
		int bonuses = prefsS[r] - (l ? prefsS[l-1] : 0);

		int needExtra = max(0LL, cover - bonuses - f);
		int reps = (needExtra / s[l]) + (needExtra % s[l] != 0);

		t += cover + reps * k;
		f = f + bonuses + reps * s[l] - cover;
	}

	cout << t << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
