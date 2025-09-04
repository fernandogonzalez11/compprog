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

int solve() {
    int n, x;
	cin >> n >> x;
	vec<int> v(n+1);
	v[0] = -1;

	map<int,int> m;

	loop(i,1,n+1) {
		cin >> v[i];
		m[v[i]]++;
	}

	sort(v.begin(), v.end());

	int mex = -1;

	loop(i,1,n+2) {
		if (i == n+1) mex = v[n]+1;
		else if (v[i] - v[i-1] > 1) {
			mex = v[i-1]+1;
			break;
		}
	}

	// cout << "m:" << mex << "\n";

	loop(i,1,n+1) {
		if (v[i] - v[i-1] > 1) {
			// skipped some numbers here
			int l = v[i-1]+1;
			int r = v[i]-1;

			for (int nn = l; nn <= r; nn++) {
				// check if i can prevent this mex
				if (nn - x < 0) return mex;

				int could = false;
				int test_k = nn/x;
				loop(i,1,test_k+1)
					if (m[mex - test_k * x] > 1) {
						m[mex - test_k * x]--;
						could = true;
						break;
					}

				if (!could) return mex;
			}
		}
	}

	// all mexes fixed across the array (or no mexes for that matter)
	mex = v[n]+1;

	for (int nn = mex; ; nn++) {
		// check if i can prevent this mex
		if (nn - x < 0) return mex;

		int could = false;
		int test_k = nn/x;
		loop(i,1,test_k+1)
			if (m[mex - test_k * x] > 1) {
				m[mex - test_k * x]--;
				could = true;
				break;
			}

		if (!could) return nn;
	}

	return mex;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}
