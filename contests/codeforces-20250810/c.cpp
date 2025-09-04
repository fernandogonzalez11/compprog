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

bool solve() {
    /*
	FIXED k
	doing op1 then op2 will do nothing	
	*/

	map<int,int> a,b;

	int n, k;
	cin >> n >> k;

	loop(i,0,n) {
		int x; cin >> x;
		a[x]++;
	}

	loop(i,0,n) {
		int x; cin >> x;
		b[x]++;
	}

	map<int,int> mods;

	for (auto p : a) {
		int m = min(p.S, b[p.F]);
		a[p.F] -= m;
		b[p.F] -= m;

		mods[p.F % k] += a[p.F];
	}

	for (auto p : b) {
		if (p.S == 0) continue;

		int s1 = p.F % k, s2 = (-p.F % k + k) % k;

		int n1 = mods[s1], n2 = mods[s2];
		if (n1 + (s2 == s1 ? 0 : n2) < p.S) return false;

		int rmv = p.S;
		int rmv1 = min(rmv, n1);
		mods[s1] -= rmv1;
		rmv -= rmv1;
		mods[s2] -= rmv;
	}

	for (auto p : mods)
		if (p.S != 0) return false;
	
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
