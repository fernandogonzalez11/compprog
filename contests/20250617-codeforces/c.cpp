#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";
 

using namespace std;

int solve() {
    int n, m; cin >> n >> m;
	vec<vec<int>> v(n, vec<int>(m));

	int mmax = -1;
	vec<pair<int,int>> mmaxpos;
	loop(i,0,n) {
		loop(k,0,m) {
			cin >> v[i][k];
			if (v[i][k] > mmax) {
				mmax = v[i][k];
				mmaxpos = {{i,k}};
			} else if (v[i][k] == mmax) {
				mmaxpos.push_back({i,k});
			}
		}
	}

	int chooseRow = mmaxpos[0].F, chooseCol = -1;
	bool can = true;
	loop(i,1,mmaxpos.size()) {
		auto pos = mmaxpos[i];
		if (chooseCol == -1) {
			if (chooseRow != pos.F) chooseCol = pos.S;
		} else {
			if (chooseRow != pos.F && chooseCol != pos.S) {
				can = false;
				break;
			}
		}
	}

	if (can) return mmax-1;

	chooseRow = -1, chooseCol = mmaxpos[0].S;
	can = true;
	loop(i,1,mmaxpos.size()) {
		auto pos = mmaxpos[i];
		if (chooseRow == -1) {
			if (chooseCol != pos.S) chooseRow = pos.F;
		} else {
			if (chooseRow != pos.F && chooseCol != pos.S) {
				can = false;
				break;
			}
		}
	}

	return mmax - can;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	START_TIMER
	while (t--) cout << solve() << "\n";
	END_TIMER

	return 0;
}
