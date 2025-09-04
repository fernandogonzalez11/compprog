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

    /*
    obs:


    hyp:
    all pos -> do all by themselves
    we should minimize negatives multiplied by big nums?
    pos number mult by big num, might overshadow neg number mult by big num

    sol:
    */

    int m = v[0];

    int dp[n][n];
    loop(i,0,n)
        loop(j,0,n)
            dp[i][j] = -INF;

    loop(i,0,2) {
        dp[1][i] = v[1] * i;
    }

    loop(i,1,n-1) {
        loop(j,1,i+1) {
            int valNext = dp[i][j-1] + (v[i+1] * j);

            dp[i+1][j-1] = max(dp[i+1][j-1], valNext);

            int valNextDown = dp[i][j-1] + (v[i+1] * (j+1));

            dp[i+1][j] = max(dp[i+1][j], valNextDown);
        }
    }

    int M = -INF;

    // cout << M << "\n";

    // vec<int> a(dp[n-1], dp[n-1]+n);
    // printarr(a);


    loop(i,0,n) {
        M = max(M, dp[n-1][i]);
    }

    cout << m + M << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
