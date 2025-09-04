#include <bits/stdc++.h>
#include <cstdio>
#include <string>

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
	scanf("%lld", &n);

	string s = to_string(n);
	loop(i,1,n+1) s += " " + to_string(i);

	map<int, vec<int>> allQ;

	int M = -1;
	// ? i n 1 2 ... n
	loop(i,1,n+1) {
		int x;
		printf("? %lld %s\n", i, s.c_str());
		fflush(stdout);

		scanf("%lld", &x);
		allQ[x].push_back(i);
		M = max(M, x);
	}

	vec<int> path(M);
	path[0] = allQ[M][0];

	for (int i = M-1; i >= 0; i--) {
		auto v = allQ[i];
		if (v.size() == 1) path[M-i] = v[0];
		else for (auto node : v) {
			int x;
			printf("? %lld 2 %lld %lld\n", path[M-i-1], path[M-i-1], node);
			fflush(stdout);
			
			scanf("%lld", &x);
			if (x == 2) {
				path[M-i] = node;
				break;
			}
		}
	}

	printf("! %lld", (int)path.size());
	loop(i,0,path.size()) {
		printf(" %lld", path[i]);
	}
	printf("\n");
	fflush(stdout);
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	
	int t = 1;
	// cin >> t;
	scanf("%lld", &t);
	while (t--) solve();
	exit(0);

	return 0;
}
