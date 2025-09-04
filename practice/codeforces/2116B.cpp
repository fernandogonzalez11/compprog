#include <bits/stdc++.h>
#include <cmath>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define MOD 998244353

using namespace std;

int binexpmod(int n, int e, int mod) {
	if (e == 0) return 1;
	
	if (e&1) return (n * binexpmod(n, e-1, mod)) % mod;

	int x = binexpmod(n, e/2, mod); // <= mod
	return (x * x) % mod;
}

void solve() {
    int n; cin >> n;
	vec<int> p(n), q(n);
	loop(i,0,n) cin >> p[i];
	loop(i,0,n) cin >> q[i];

	// store max p and max q per day, as indices
	vec<int> maxP(n), maxQ(n);
	maxP[0] = 0;
	maxQ[0] = 0;

	loop(i,1,n) {
		if (p[i] > p[maxP[i-1]]) maxP[i] = i;
		else maxP[i] = maxP[i-1];

		if (q[i] > q[maxQ[i-1]]) maxQ[i] = i;
		else maxQ[i] = maxQ[i-1];
	}

	// get r_i as operating with the max between maxP[i] and maxQ[i]
	loop(i,0,n) {
		int res = -1;
		// choosing the max p is better
		if (p[maxP[i]] > q[maxQ[i]]) {
			res = (
				binexpmod(2, p[maxP[i]], MOD) + 
				binexpmod(2, q[i - maxP[i]], MOD)
			) % MOD;
		}
		// choosing the max q is better
		else if (q[maxQ[i]] > p[maxP[i]]) {
			res = (
				binexpmod(2, q[maxQ[i]], MOD) + 
				binexpmod(2, p[i - maxQ[i]], MOD)
			) % MOD;
		}
		// same on both ends => get the best second operand
		else {
			int op2 = max(q[i - maxP[i]], p[i - maxQ[i]]);
			res = (
				binexpmod(2, p[maxP[i]], MOD) + // any of them work
				binexpmod(2, op2, MOD)
			) % MOD;
		}

		cout << res << " ";
	}

	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
