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

#define pii pair<int,int>

using namespace std;

typedef struct distPair {
	pii a, b;
	int dist;

	distPair(pii aa, pii bb) {
		a = aa;
		b = bb;
		dist = abs(a.F - b.F) + abs(a.S - b.S);
	}

	bool operator<(distPair x) {
		return dist < x.dist;
	}

	bool operator>(distPair x) {
		return dist > x.dist;
	}
} distPair;

void solve() {
    int n;
	cin >> n;
	vec<pii> v(n);
	vec<int> idx(n);
	loop(i,0,n) cin >> v[i].F >> v[i].S;
	loop(i,0,n) idx[i] = i;


	/* think of it like a map
	.       .         |          .   
	 . .            . |       .         .
	          .    .  | ..               . 
	--------------------------------------
	.     .       .   |              . .          
	 .                | .          .     
	  .             . |     .           .
					  |
	pair lower left part with upper right
	pair upper left part with lower right

	these four sets are disjoint ^ and
	also render all the points
	*/

	set<int> xl, xr, yl, yr;
	sort(idx.begin(), idx.end(), [&](int &a, int &b) {
		return v[a].F < v[b].F;
	});
	loop(i,0,n/2) xl.insert(idx[i]);
	loop(i,n/2,n) xr.insert(idx[i]);

	sort(idx.begin(), idx.end(), [&](int &a, int &b) {
		return v[a].S < v[b].S;
	});
	loop(i,0,n/2) yl.insert(idx[i]);
	loop(i,n/2,n) yr.insert(idx[i]);
	
	// pair lower left part (xl & yl) with upper right (xr & yr)
	// pair upper left part (xl & yr) with lower right (xr & yl)
	vec<int> lowl, lowr, uppl, uppr;
	for (int i : yl) {
		if (xl.count(i)) lowl.push_back(i);
		else lowr.push_back(i);
	}

	for (int i : yr) {
		if (xl.count(i)) uppl.push_back(i);
		else uppr.push_back(i);
	}

	loop(i,0,lowl.size()) cout << lowl[i]+1 << " " << uppr[i]+1 << "\n";
	loop(i,0,lowr.size()) cout << lowr[i]+1 << " " << uppl[i]+1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
