#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
	for (auto x : a) cout << x << " "; \
	cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

void solve() {
	int n,m,k;
	cin>>n>>m>>k;

	int a = k-1, b = n-k;
	if (a>b) swap(a,b);

	// r-1 + r + r = 3r - 1 <= m
	int r = (m+1)/3;

	if (r < a) {
		m -= 3*r - 1;
		return void(cout << 1+2*r+(m>=2) << "\n");
	}
	else {
		m -= 3*a - 1;
		// a will be filled on both sides
		// adding one more to the right takes 2 days (1 add + 1 mov)
		int extra = min(b-a, m/2);
		cout << 1+2*a+extra << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
