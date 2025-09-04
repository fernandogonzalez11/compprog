#include <algorithm>
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

bool allZero(map<int, int> m) {
	for (auto p : m) {
		if (p.S > 0) return false;
	}

	return true;
}

void solve() {
	int n;
	cin >> n;
	
	vec<int> v(n);
	map<int, int> m;
	set<int> s;
	loop(i,0,n) {
		cin >> v[i];
		m[v[i]]++;
		s.insert(v[i]);
	}

	

	sort(v.begin(), v.end());
	
	int segments = 0;
	while (!allZero(m)) {
		// scanline
		int cur = 0;
		vec<int> sV(s.begin(), s.end());
		loop(i,0,sV.size()) {
			// cout << "m of " << sV[i] << " now " << m[sV[i]] << "\n";
			

			// if (sV[i] - sV[i-1] >= 2 || m[sV[i-1]] <= 0) segments++;
			if (m[sV[i]] == 0) {
				if (cur) {
					segments++;
					cur = 0;
				}
			} else {
				if (--m[sV[i]] == 0) s.erase(sV[i]);

				if (i > 0 && sV[i] - sV[i-1] >= 2) {
					segments++;
					cur = 1;
				} else cur++;
				// cout << "m of " << sV[i] << " now " << m[sV[i]] << "\n";
			}
		}
		
		if (cur) {
			segments++;
		}
	}

	cout << segments << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
