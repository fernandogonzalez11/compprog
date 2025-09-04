#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
// #define F first
// #define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

int n, k;
vec<int> v;

bool f(int S) {
	int cnt = 1;
	int val = 0;

	int i = 0;
	while (i < n) {
		if (v[i] > S) return false; 

		if (val + v[i] > S) {
			val = v[i];
			cnt++;
		} else {
			val += v[i];
		}

		i++;
	}

	return cnt <= k;
}

void solve() {
	cin >> n >> k;

	v.resize(n);
	loop(i,0,n) cin >> v[i];

	// find min s
	int l = 0, r = 1;
	while (!f(r)) r *= 2;

	while (r-l > 1) {
		int S = (r-l)/2+l;
		if (!f(S)) l = S;
		else r = S;
	}

	cout << r << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
