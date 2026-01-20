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
	int n,m,x;
	cin>>n>>m>>x;

	queue<int> q;
	// turn into +- mod n
	q.push(x-1);

	loop(i,0,m) {
		int d;
		char o;
		cin>>d>>o;

		int sz = q.size();
		set<int> s;
		loop(_,0,sz) {
			int val = q.front();
			q.pop();

			int val1 = (val+d)%n, val2 = (val-d+n)%n;
			if (o=='?') {
				s.insert(val1);
				s.insert(val2);
			} else if (o == '0') {
				s.insert(val1);
			} else {
				s.insert(val2);
			}
		}

		for (auto p : s) q.push(p);
	}

	vec<int> lasting;
	int sz = q.size();
	loop(i,0,sz) {
		lasting.push_back(q.front());
		q.pop();
	}
	sort(all(lasting));
	cout << sz << "\n";
	loop(i,0,sz) cout << lasting[i]+1 << " ";
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
