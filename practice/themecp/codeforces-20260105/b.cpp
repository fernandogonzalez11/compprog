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
	int n;
	cin>>n;
	vec<int> a(n),b(n);
	loop(i,0,n) cin>>a[i];
	loop(i,0,n) cin>>b[i];

	bool w = true, wrev = true;
	for (int i = 0; i < n; i++) w &= a[i]==b[i];
	for (int i = 0; i < n; i++) wrev &= a[i]==b[n-1-i];

	if (!(w||wrev)) cout << "Alice\n";
	else cout << "Bob\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
