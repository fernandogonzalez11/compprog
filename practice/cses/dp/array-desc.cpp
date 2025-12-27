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

using namespace std;

const int MOD = 1e9+7;
using pii = pair<int,int>;

void solve() {
    int n,m;
	cin>>n>>m;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	// vec<int> dp(n+1);
	// dp[0] = 1;
	// loop(i,1,n+1) {
	// 	if (v[i-1] != 0) dp[i] = dp[i-1];
	// 	else {
	// 		int val = 0;
	// 		loop(mm,0,m+1) {
	// 			bool works = true;
	// 			if (i > 1) works &= (abs(v[i-2]-mm)<=1);
	// 			if (i < n) works &= (abs(v[i]-mm)<=1);
	// 			if (works) val = (val+dp[i-1]) % MOD;
	// 		}
	// 		dp[i] = val;
	// 	}
	// }

	// cout << dp[n] << "\n";

	if (n==1) {
		cout << ((v[0]==0) ? m : 1) << "\n";
	}

	// bfs
	// pair: (last chosen, next i to choose)
	int cnt = 0;
	queue<pii> q;
	if (v[0]>0) q.push({v[0],1});
	else {
		loop(mm,1,m+1) {
			if (v[1]==0 || abs(v[1]-v[0])<=1)
				q.push({mm,1});
		}
	}

	while (!q.empty()) {
		int last, nexti;
		tie(last,nexti) = q.front();
		q.pop();

		if (nexti>=n) cnt = (cnt+1)%MOD;
		else if (v.at(nexti)>0) q.push({v[nexti],nexti+1});
		else {
			loop(mm,1,m+1) {
				if (abs(mm-last)>1) continue;
				if (nexti+1 < n && v[nexti+1]>0 && abs(mm-v[nexti+1])>1) continue;
				q.push({mm, nexti+1});
			}			
		}
	}

	cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
