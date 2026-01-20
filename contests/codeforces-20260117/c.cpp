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
	string s;
	cin>>s;

	vec<bool> can(n,true);

	int l = 0, r = n-1;
	for (; l < n; l++) {
		if (s[l]=='1') break;
		can[l] = false;
	}

	for (; r >= 0; r--) {
		if (s[r]=='0') break;
		can[r] = false;
	}

	if (!(l<r)) {
		cout << "Bob\n";
		return;
	}

	for (int i = l; i <= r-1; i++) {
		if (!can[i]) continue;
		// "inversion"
		if (s[i]=='0'&&s[i+1]=='1') {
			can[i] = can[i+1] = false;
		}
	}

	int za, oa;
	za=oa=0;
	vec<int> move;
	loop(i,0,n) {
		if (can[i]) {
			s[i]=='0' ? za++ : oa++;
			move.push_back(i+1);
		}
	}

	bool alice = za&&oa;
	cout << (alice ? "Alice\n" : "Bob\n");
	if (alice) {
		cout << move.size() << "\n";
		loop(i,0,move.size()) cout << move[i] << " ";
		cout << "\n";
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
