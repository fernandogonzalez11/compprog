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

const int POWC = 25;
int *pows;

inline int c(int x) {
	return 3 * pows[x] + x * pows[x] / 3;
}

void solve() {
    int n, k;
	cin >> n >> k;

	int n2 = n;

	int cost = 0;
	int deals = 0;

	for (int i = POWC-1; i >= 0; i--) {
		while (n >= pows[i]) {
			n -= pows[i];
			cost += 3 * pows[i] + i * pows[i] / 3;
			deals++;
		}
	}

	if (deals > k) {
		cout << "-1\n";
		return;
	}

	int spare = k-deals;
	n = n2;

	// cout << "--" << n << " " << k << "\n";
	cout << "--" << cost << " " << spare << "\n";

	for (int i = POWC-1; i >= 1; i--) {
		while (n >= pows[i]) {
			n -= pows[i];
			if (spare >= 2) {
				// cout << "#$" << pows[i-1] << "\n";
				cost -= pows[i-1];
				spare -= 2;
			}
		}
	}

	cout << cost << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	pows = new int[POWC];
	pows[0] = 1;
	loop(i,1,POWC) pows[i] = 3 * pows[i-1];

	// loop(i,0,POWC) cout << pows[i] << " " << "\n"; 
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
