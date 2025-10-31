#include <bits/stdc++.h>
#include <cstdio>

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
    int n,m;
	cin >> n >> m;
	vec<pair<int,int>> road(n);
	vec<pair<int,int>> jour(m);

	loop(i,0,n) cin >> road[i].F >> road[i].S;
	loop(i,0,m) cin >> jour[i].F >> jour[i].S;

	int i = 0, j = 0;
	int curSegR = 0, curSegJ = 0;
	int amt = 0;
	loop(s,1,100+1) {
		if (curSegR++ >= road.at(i).F) {
			curSegR = 1;
			i++;
		}

		if (curSegJ++ >= jour.at(j).F) {
			curSegJ = 1;
			j++;
		}

		amt = max(amt, jour.at(j).S - road.at(i).S);
	}

	cout << amt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
