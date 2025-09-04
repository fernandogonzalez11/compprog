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
    int n,m,q;
	cin >> n >> m >> q;

	int t1,t2,s;
	cin >> t1 >> t2 >> s;
	t1--; t2--; s--; n--;

	if (t1 > t2) swap(t1, t2);

	int amt = 0;

	if (t1 < s && s < t2) {
		int k = (s-t1-1)/2;
		amt += k;
		s -= k;
		t1 += k;
		t2 -= k;

		k = (t2-s-1)/2;
		amt += k;
		s += k;
		t1 += k;
		t2 -= k;

		if (s - t1 == 2 && t2 - s == 2) amt++;
		amt++;
	} else if (t1 > s) {
		amt += s;
		t1 -= s;
		amt += t1;
	} else {
		amt += (n-s);
		t2 += (n-s);
		amt += (n-t2);
	}

	cout << amt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
