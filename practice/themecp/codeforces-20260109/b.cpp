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

int ceil(int a, int b) {
	return a/b + (a%b>0);
}

void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	cin>>s;

	// int seg = 0, ops;
	// loop(i,0,n) {
	// 	if (s[i]=='0') {
	// 		int sz = 0;
	// 		while (i<n && s[i++]=='0') sz++;
	// 		if (sz >= m) seg += ceil(sz, m);
	// 		i--;
	// 	}
	// }

	// if (k==1) {
	// 	ops = seg;
	// } else if (k < m) {
	// 	ops = ceil(seg, 2LL);
	// } else {
	// 	int mod = k%m;
	// 	int u = k/m;

	// 	if (mod==0) ops = ceil(seg, u);
	// 	else if (mod==1) ops = ceil(seg, u+1);
	// 	else ops = ceil(seg, u+2);
	// }

	// cout << ops << "\n";

	int ops = 0, cnt = 0;
	loop(i,0,n) {
		if (s[i]=='1') cnt = 0;
		else {
			cnt++;
			if (cnt == m) {
				ops++;
				i += k-1;
				cnt = 0;
			}
		}
	}

	cout << ops << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
