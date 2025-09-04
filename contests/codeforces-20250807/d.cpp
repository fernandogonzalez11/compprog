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

bool solve() {
    int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	int le = v[0];
	loop(i,1,n) {
		int split1, split2;
		split1 = split2 = v[i]/2;
		
		if (v[i] % 2 == 0) split1--;
		split2++;

		if (!(split1 >= 0 && split2 <= le)) return false;
		le = min(le, v[i]);
	}

	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "YES\n" : "NO\n");

	return 0;
}
