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

int solve() {
	int s,k,m;
	cin>>s>>k>>m;

	if (s <= k) {
		m %= k;
		return max(0LL, s-m);
	} else {
		m %= 2*k;
		if (m < k) return s-m;
		return k-(m-k);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout<<solve()<<"\n";

	return 0;
}
