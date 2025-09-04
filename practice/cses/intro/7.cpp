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
    loop(n, 1, t+1) {
		int n1 = n * n;
		n1 = (n1%2==0) ? n1/2*(n1-1) : (n1-1)/2*n1;
		n1 -= 4*(n-1)*(n-2);

		cout << n1 << "\n";
	}

	return 0;
}
