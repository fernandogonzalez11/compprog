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
	int n,k;
	cin>>n>>k;

	if (k > n) {
		cout << "-1\n";
		return;
	}

	set<int> s;
	queue<int> q;

	int steps = 0;
	q.push(n);

	while (!s.count(0)) {
		int sz = q.size();

		loop(i,0,sz) {
			int x = q.front();
			q.pop();

			if (x == k) {
				cout << steps << "\n";
				return;
			}

			int x1 = x/2, x2 = x-x1;
			if (!s.count(x1)) {
				q.push(x1);
				s.insert(x1);
			}

			if (!s.count(x2)) {
				q.push(x2);
				s.insert(x2);
			}
		}
		steps++;
	}

	cout << "-1\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
