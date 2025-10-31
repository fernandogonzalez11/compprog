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
	vec<int> b(n), a(n, -1);

	loop(i,0,n) cin >> b[i];

	a[0] = 1;

	// int put = 2;
	// int curDistinct = 1;
	// int nextSum = 3;
	// loop(i,1,n) {
	// 	cout << "n:"<< nextSum << "\n";

	// 	int dif = nextSum - v[i];
	// 	cout << "dif:" << dif << "\n";
	// 	if (dif == 0) {
	// 		a[i] = put++;
	// 		nextSum = 1 + nextSum + i+1;
	// 		curDistinct++;
	// 	} else {
	// 		a[i] = a[dif - 1];
	// 		nextSum = 1 + nextSum + dif;
	// 	}
	// }

	int put = 2;
	int curSum = 1, nextSum;
	loop(i,1,n) {
		// assume we will put a new number
		nextSum = 1 + curSum + i;
		int dif = nextSum - b[i];

		cout << "b4: " << curSum << " " << nextSum << " " << dif << "\n";

		if (dif == 0) {
			a[i] = put++;
			// next sum is what we predicted
		} else {
			a[i] = a[dif - 1];
			// if we dont, the next sum will change
			nextSum = 1 + curSum + dif-1;
		}

		cout << "af: " << nextSum << ", chose " << a[i] << "\n";

		curSum = nextSum;
	}

	printarr(a);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
