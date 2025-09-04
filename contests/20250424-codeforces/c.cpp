#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
// #define int long long

using namespace std;

int solve() {
    int n, k; cin >> n >> k;

	vec<int> a(n);
	vec<int> b(n); 
	loop(i, 0, n) cin >> a[i];
	loop(i, 0, n) cin >> b[i];

	int setX = -1;
	int M = a[0], m = a[0];
	loop(i, 0, n) {
		M = max(M, a[i]);
		m = min(m, a[i]);
		if (a[i] >= 0 && b[i] >= 0) {
			int x = a[i] + b[i];
			if (setX >= 0 && x != setX) return 0;
			setX = x;
		}
	}

	// cout << " : " << M << " " << m << "\n";

	// 1 or 0
	if (setX >= 0) {
		loop(i, 0, n) {
			int comp = setX - a[i];
			if (b[i] < 0 && (comp < 0 || comp > k)) return 0;
		}
		return 1;
	// many possibilites
	} else {
		return k - (M - m) + 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) cout << solve() << "\n";

	return 0;
}
