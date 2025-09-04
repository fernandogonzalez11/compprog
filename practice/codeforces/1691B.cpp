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

void solve() {
	int n; cin >> n;
	vec<int> s(n);
	loop(i,0,n) cin >> s[i];

	int i, j;
	i = j = n-1;

	vec<int> res(n);

	bool cant = false;

	while (i >= 0) {
		if (i == 0) {
			cant = true;
			break;
		}

		while (j >= 0 && s[i] == s[j]) j--;
		j++;

		if (i == j) {
			cant = true;
			break;
		}

		// otherwise, output a cyclic shift from the indices
		res[j] = i;
		loop(k, j, i) res[k+1] = k;

		i = --j;
	}
	
	if (cant) cout << -1 << "\n";
	else {
		for (int r : res) cout << r+1 << " ";
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
