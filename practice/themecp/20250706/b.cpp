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
    // cards form a partition
	int n, m;
	cin >> n >> m;

	vec<vec<int>> cards(n, vec<int>(m));
	loop(i,0,n) {
		loop(j,0,m) {
			cin >> cards[i][j];
		}
		sort(cards[i].begin(), cards[i].end());
	}

	vec<pair<int, int>> col(n);
	loop(i,0,n) col[i] = {cards[i][0], i};
	sort(col.begin(), col.end());

	//loop(i,0,n) cout << col[i].F << " " << col[i].S << "\n";

	int top = -1;
	loop(j,0,m) {
		loop(i,0,n) {
			if (cards[col[i].S][j] < top) {
				cout << -1 << "\n";
				return;
			}

			top = cards[col[i].S][j];
		}
	}

	// if i can play the whole game, awesome
	loop(i,0,n) cout << col[i].S+1 << " ";
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
