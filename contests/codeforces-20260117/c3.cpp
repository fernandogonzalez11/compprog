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
	string s,s2;
	cin>>s;

	s2 = s;
	sort(all(s2));

	if (s2==s) return void(cout << "Bob\n");

	cout << "Alice\n";
	vec<int> move;
	loop(i,0,n) {
		if (s[i] != s2[i]) move.push_back(i+1);
	}
	cout << move.size() << "\n";
	for (auto x : move) cout << x << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
