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

int get(map<int,int> &m, int x) {
	// cout << "get:\n";
	// for (auto p : m) cout << p.F << " " << p.S << "\n";

	for (auto p : m) {
		if (p.S == x) return p.F;
	}

	// shouldnt happen????
	return -1;
}

void solve() {
    int n;
	cin >> n;

	map<int, int> ms[n-1];
	loop(i,0,n)
		loop(j,0,n-1) {
			int x;
			cin >> x;
			ms[j][x]++;
		}

	int perm[n];
	fill(perm, perm+n, -1);

	int S = 0;
	int l = 0, r = n-1-1;
	while (l < r) {
		perm[l] = get(ms[l], n-1-l);
		perm[r] = get(ms[r], n-1-r);

		S += perm[l] + perm[r];

		l++;
		r--;
	}

	// printarr(perm);
	// cout << S << "\n";

	
	// if n is even we must find an extra perm elem
	if (n % 2 == 0) {
		int findI = (n-1)/2;
		perm[findI] = -1;
		for (auto p : ms[findI]) {
			int thisone = true;
			loop(i,0,n-1) {
				if (p.F == perm[i]) {
					thisone = false;
					break;
				}
			}

			if (thisone) perm[findI] = p.F;
		}

		S += perm[findI];
	}

	// cout << S << "\n";

	perm[n-1] = n*(n+1)/2 - S;

	loop(i,0,n) cout << perm[i] << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
