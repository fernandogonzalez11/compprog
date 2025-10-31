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
	
	vec<int> freqs(102, 0);
	loop(i,0,n) {
		int x;
		cin >> x;
		freqs[x]++;
	}

	if (!freqs[0]) cout << 0 << "\n";
	else {
		loop(i,1,101) {
			if (freqs[i] < freqs[i-1]) {
				// if its 0 -> exactly i
				// if its not -> the mex of all -> find the first 0
				while (freqs[i] != 0) i++;
				cout << i << "\n";
				return;
			}
		}
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
