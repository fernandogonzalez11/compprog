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
	vec<pair<int,int>> turn(n), into(n);

	loop(i,0,n) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		turn[i] = {c,d};
		into[i] = {a,b};
	}

	int ops = 0;

	int cons0 = 0, cons1 = 0;
	// empty -> nonempty piles
	loop(i,0,n) {
		if (!turn[i].F && !turn[i].S) {
			cons0 += into[i].F;
			cons1 += into[i].S;
			// necessary?
			turn[i].F = into[i].F;
			turn[i].S = into[i].S;
		}
	}

	ops += cons0 + cons1;
	// cout << ops << "\n";

	// analyze which ones we had to give to the others to construct
	loop(i,0,n) {
		int surp0 = turn[i].F - into[i].F;
		int surp1 = turn[i].S - into[i].S;

		if (surp0 > 0) {
			int given = min(cons0, surp0);
			turn[i].F -= given;
			cons0 -= given;
		}

		if (surp1 > 0) {
			int given = min(cons1, surp1);
			turn[i].S -= given;
			cons1 -= given;
		}
	}

	// loop(i,0,n) cout << turn[i].F << " " << turn[i].S << "\n";
	// cout << "missing:\n";

	loop(i,0,n) {
		int def0 = max(0LL, into[i].F - turn[i].F);
		int def1 = max(0LL, into[i].S - turn[i].S);

		// cout << def0 << " " << def1 << "\n";

		if (!def0 && !def1) continue;

		// both 1s and 0s
		if (turn[i].F && turn[i].S) {
			// bring 1s -> 0s -> swap existing 0s if needed
			ops += def1 + def0 + (def1 ? turn[i].F : 0);

		// only 1s
		} else if (!turn[i].F) {
			// bring in 1 deficits, then 0 deficits
			ops += def1 + def0;


		// only 0s
		} else {
			// min between:
				// bring 1s -> 0s -> swap deficit 1s
				// bring 0s -> 1s -> swap all 0s

			ops += def1 + def0 + (def1 ? turn[i].F : 0);
		}
	}

	loop(i,0,n) {
		int def0 = into[i].F - turn[i].F;
		ops += max(0LL, def0);
		turn[i].F += def0;
	}

	loop(i,0,n) {
		int def1 = into[i].S - turn[i].S;
		ops += max(0LL, def1) + turn[i].F;
		turn[i].S += def1;
	}

	cout << ops << "\n";

	// cout << "---\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
