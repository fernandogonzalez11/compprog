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

	int p = 0;
	vec<int> odd, even;
	loop(i,1,n+1) {
		int x;
		cin >> x;
		if (i%2) odd.push_back(x);
		else {
			if (!(x >= odd[i/2-1])) {
				p += odd[i/2-1]-x;
				odd[i/2-1]=x;
			}
			even.push_back(x);
		}
	}

	int sz = odd.size();
	loop(i,1,sz) {
		int diff = odd[i]+odd[i-1] - even[i-1];
		if (diff > 0) {
			p += diff;
			odd[i] -= diff;
			if (odd[i]<0) {
				diff += -odd[i];
				odd[i] = 0;
				odd[i-1] -= diff;
			}
		}
	}

	cout << p << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
