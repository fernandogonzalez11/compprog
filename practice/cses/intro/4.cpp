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
    
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n; cin >> n;
	vec<int> v(n);
	loop(i, 0, n) cin >> v[i];

	int c = v[0], am = 0;
	loop(i, 1, n) {
		// less => level to cur
		if (v[i] <= c)
			am += c - v[i];
		// more => set new cur
		else
		 	c = v[i];
	}

	cout << am << "\n";

	return 0;
}
