#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

#define MOD 1000000007

using namespace std;

void solve() {
    
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n; cin >> n;
	int res = 1;

	while (n--)
		res = (res << 1) % MOD;

	cout << res << "\n";

	return 0;
}
