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
    int n;
	cin >> n;

	vec<pair<int,int>> v(n);
	loop(i,0,n) cin >> v[i].F >> v[i].S;

	// multiset<int> records;
	// loop(i,0,n) records.insert(v[i].F);

	map<int, vec<int>> choices;
	// sort(v.begin(), v.end(), [&](pair<int,int> &a, pair<int,int> &b) {
	// 	return a.S < b.S && a.F < b.S;
	// });
	sort(v.begin(), v.end());

	for (auto p : v) {
		choices[p.S].push_back(p.F);
		// choices[p.F].push_back(p.F);
	}

	// for (auto c : choices) {
	// 	cout << c.F << ": ";
	// 	printarr(c.S);
	// }

	auto itI = choices.begin();
	auto itJ = itI->second.begin();

	int gotWholeSequence = true;

	loop(i,0,n) {
		while (*itJ != v[i].F) {
			if (++itJ == itI->second.end()) {
				if (++itI == choices.end()) {
					gotWholeSequence = false;
					break;
				}
				itJ = itI->second.begin();
			}
		}

		if (!gotWholeSequence) break;
		// otherwise it did find a member (& itI exists)
		// pick it
		
		// advance 1 more
		// if this isnt the last number and there are no more to exhaust, we didnt get it all
		if (i != n-1 && ++itJ == itI->second.end()) {
			if (++itI == choices.end()) {
				gotWholeSequence = false;
				break;
			}
			itJ = itI->second.begin();
		}
	}

	cout << (gotWholeSequence ? itI->first : v[n-1].F) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
