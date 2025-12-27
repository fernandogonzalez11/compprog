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

int cnt1s(vec<int> &v) {
	int cnt = 0;
	for (int i : v) cnt += (i==1);
	return cnt;
}

void solve() {
    int n;
	cin >> n;
	vec<int> a(n),b(n);
	loop(i,0,n) cin >> a[i];
	loop(i,0,n) cin >> b[i];

	int aCnt = cnt1s(a), bCnt = cnt1s(b);
	if (aCnt%2 == bCnt%2) cout << "Tie\n";
	else {
		// %2 == 1 -> win
		loop(i,0,n) {
			bool aTurn = i%2 == 0; // true: ajisai
			if (aTurn) {
				if (aCnt%2 == 0 && a[i]!=b[i]) {
					aCnt++;
					bCnt--;
				}
			} else {
				if (bCnt%2 == 0 && a[i]!=b[i]) {
					aCnt++;
					bCnt--;
				}
			}
		}

		if (aCnt%2 == 1) cout << "Ajisai\n";
		else cout << "Mai\n";
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
