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
	
    int t; cin >> t;
	int tot = 0;
	int m = 5;
	while (m <= t) {
		tot += t/m;
		m *= 5;
	}
    cout << tot << "\n";

	return 0;
}
