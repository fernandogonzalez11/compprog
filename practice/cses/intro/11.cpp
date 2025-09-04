#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

bool solve() {
    int a, b; cin >> a >> b;
	if (b > a) {
		a = a ^ b;
		b = b ^ a;
		a = a ^ b;
	}

	// max in a, min in b
	int dif = a - b;
	a -= 2 * dif;
	b -= dif;

	// now both will be the same
	if (a < 0 || b < 0) return false;
	if (a % 3 != 0) return false;
	// now both will be mult 3
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) cout << (solve() ? "YES" : "NO") << "\n";

    

	return 0;
}
