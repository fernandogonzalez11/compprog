#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
// #define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
    int n;
	cin >> n;

	// O(n^4) crazy shit
	vector<int> v(n);
	int M = 0;
	for (int num = 1; num <= n; num++) {
		for (int pos = 1; pos <= n; pos++) {
			fill(v.begin(),v.end(),0);
			v[pos-1] = num;

			// all pi*i < num*pos
			bool found = false;
			for (int num2 = n; num2 >= 1; num2--) {
				if (num2==num) continue;
				found = false;
				for (int pos2 = n; pos2 >= 1; pos2--) {
					if (v[pos2-1]>0) continue;
					if (num2*pos2 <= num*pos) {
						found = true;
						v[pos2-1] = num2;
						break;
					}
				}
				if (!found) break;
			}
			if (!found) continue;

			{
				int mm=0, s=0;
				for (int pos = 1; pos <= n; pos++) {
					mm = max(mm, pos*v[pos-1]);
					s += pos*v[pos-1];
				}

				M = max(M, s-mm);

				// cout << M << " ";
				// printarr(v);
			}
		}
	}

	cout << M << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
