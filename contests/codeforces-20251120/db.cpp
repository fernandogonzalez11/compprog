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

void solve() {
    int n;
	cin >> n;
	vec<int> p(n);
	loop(i,0,n) cin >> p[i];

	vec<bool> vis(n, 0);
	queue<int> q;
	q.push(0);
	vis[0] = true;

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		for (int j = i+1; j < n; j++) {
			if (vis[j]) continue;
			if (p[i]<p[j]) {
				q.push(j);
				vis[j]=true;
			}
		}
	}

	bool h = true;
	loop(i,0,n) h &= vis[i];
	cout << (h?"Yes\n":"No\n");
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
