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
	if (n == 1) cout << 1 << "\n";
	else if (n == 4) cout << 2 << " " << 4 << " " << 1 << " " << 3 << "\n";
	else if (n > 1 && n < 5) cout << "NO SOLUTION";
	else {
		for (int i = 1; i <= n; i += 2) cout << i << " ";
		for (int i = 2; i <= n; i += 2) cout << i << " ";
	}

	return 0;
}
