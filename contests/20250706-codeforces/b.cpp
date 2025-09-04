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
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	vec<int> pM(n);
	pM[0] = v[0];
	loop(i,1,n) pM[i] = min(pM[i-1], v[i]);

	vec<int> pMS(n);
	pMS[0] = pM[0];
	loop(i,1,n) pMS[i] = pMS[i-1] + pM[i];

	int res = pMS[n-1];

	vec<int> dontAffect;
	loop(i,1,n) {
		if (pM[i] != pM[i-1]) continue;
		dontAffect.push_back(i);
	}
		

	if (dontAffect.empty()) {
		cout << res << "\n";
		return;
	}

	// printarr(dontAffect);

	int ptr = dontAffect.size() - 1;

	for (int j = n-1; j >= 1; j--) {
		// choose this one as j -> all prefix mins become 0 -> our new sum is pMS[j-1] 
		// but we need to sum a[j] to some element
		// can we keep this pMS[j-1] by doing an addition?
		// find an element that doesnt affect the prefix min
		// someone in dontAffect that has dontAffect[ptr] < j
		// if i get to the start? i cant do no more

		int potentialSum = pMS[j-1];

		bool br = false;
		if (ptr == -1) break;
		while (dontAffect[ptr] >= j) {
			ptr--;
			if (ptr == -1) {
				br = true;
				break;
			}
		}

		if (br) break;
		res = potentialSum;
	}

	cout << res << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
