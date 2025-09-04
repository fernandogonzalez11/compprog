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
		turn[i] = {a,b};
		into[i] = {c,d};
	}

	int ops = 0;

	// 0 surplus out, redistrib as follows
	/*
	0 existing
	1 surplus
	0 extra needed
	1 existing
	*/
	loop(i,0,n) {
		int surp0 = turn[i].F - into[i].F;
		ops += max(0LL, surp0);
	}

	// swap 0 existing with 1 surplus
	// if there was 0 surplus, we swap into[i]
	// if there was 0 deficit, we swap turn[i]
	/*
	1 surplus
	0 extra needed
	0 existing
	1 existing
	*/
	loop(i,0,n) {
		int surp1 = turn[i].S - into[i].S;
		if (surp1 > 0) ops += min(into[i].F, turn[i].F);
	}

	// 1 surplus out, redistrib as follows
	/*
	0 extra needed
	0 existing
	1 extra needed
	1 existing
	*/
	loop(i,0,n) {
		int surp1 = turn[i].S - into[i].S;
		ops += max(0LL, surp1);
	}

	cout << ops << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
