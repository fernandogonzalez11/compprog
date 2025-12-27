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
    cin>>n;

    vec<int> steps(n+1, INF);
    steps[0] = 0;
    loop(x,1,n+1) {
        int val = INF;
        int x2 = x;
        while (x2) {
            val = min(val, 1+steps[x-(x2%10)]);
            x2 /= 10;
        }
        steps[x] = val;
    }

    // printarr(steps);

    cout << steps[n] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
