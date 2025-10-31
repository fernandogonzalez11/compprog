#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

vec<int> pos;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int smallestFactDoesntDivide(int x) {
	int a = 2;
	while (gcd(a, x) != 1) a++;
	return a;
}

void solve() {
    int n;
	cin >> n;
	pos.resize(n);
	loop(i,0,n) cin >> pos[i];

	int G = pos[0];
	loop(i,1,n) G = gcd(G, pos[i]);

	// cout << G << "\n";

	if (G == 1) cout << 2 << "\n";
	else cout << smallestFactDoesntDivide(G) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
