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

int TEST = 1;

bool solve() {
    int n, m, k;
	cin >> n >> m >> k;

	// if (TEST == 16) cout << n << " " << m << " " << k << "\n";

	unordered_set<int> A, B;
	loop(i,0,n) {
		int x; cin >> x;
		if (1 <= x && x <= k) A.insert(x);
	}

	loop(i,0,m) {
		int x; cin >> x;
		if (1 <= x && x <= k) B.insert(x);
	}

	if (!(A.size() >= k/2 && B.size() >= k/2)) return false;

	int difACard = 0, difBCard = 0;
	loop(i,1,k+1) {
		if (!(A.count(i) || B.count(i))) return false;
		if (A.count(i) && !B.count(i)) difACard++;
		else if (B.count(i) && !A.count(i)) difBCard++;
	}

	return difACard <= k/2 && difBCard <= k/2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) {cout << (solve() ? "YES\n" : "NO\n"); TEST++;}

	return 0;
}
