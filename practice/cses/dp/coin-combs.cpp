#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
// #define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

const int MOD = 1e9+7;

using namespace std;

void solve() {
    int n,x;
    cin>>n>>x;

    vector<int> coins(n);
    loop(i,0,n) cin>>coins[i];

    vector<vector<int>> combs(n+1, vector<int>(x+1));
    // initial vals
    loop(_x,0,x+1) combs[0][_x] = 0;
    combs[0][0] = 1;

    loop(_p,1,n+1) {
        loop(_x,0,x+1) {
            int val = combs[_p-1][_x];
            if (_x - coins.at(_p-1) >= 0) {
                val += combs.at(_p).at(_x - coins.at(_p-1));
                val %= MOD;
            }
            combs[_p][_x] = val;
        }
    }

    cout << combs[n][x] << "\n";

    // vector<int> combs(x+1);
    // combs[0] = 1;
    // loop(_x,1,x+1) {
    //     int val = 0;
    //     loop(i,0,n)
    //         if (_x - coins[i] >= 0) val += combs[_x - coins[i]];
    //     combs[_x] = val % MOD;
    // }

    // cout << combs[x];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
