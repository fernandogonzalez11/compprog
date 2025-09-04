#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

bool inrange(int a, int b, int c) {
	if (b > c) swap(b, c);
	return (b <= a && a <= c) || (b <= a-1 && a-1 <= c) || (b <= a+1 && a+1 <= c);
}

void solve() {
    int n;
	cin >> n;

	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	if (n == 2 && abs(v[0] - v[1]) > 1) {
		cout << -1 << "\n";
		return;
	}

	loop(i,0,n-1) {
		if (abs(v[i] - v[i+1]) <= 1) {
			cout << 0 << "\n";
			return;
		}
	}

	loop(i,0,n-2) {
		if (inrange(v[i], v[i+1], v[i+2]) || inrange(v[i+2], v[i], v[i+1])) {
			cout << 1 << "\n";
			return;
		}
	}

	cout << -1 << "\n";
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
