#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

void solve() {
    int x; cin >> x;

	int i = 0, prev = 0, steps = 0;
	while (i <= x) {
		prev = i;
		i *= 2;
		i++;
		steps++;
	}

	steps--;
	steps <<= 1;

	if (prev == x) cout << steps + 1 << "\n";
	else cout << steps + 3 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
