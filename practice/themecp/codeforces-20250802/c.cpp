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

vec<int> fact(int k) {
	vec<int> f;
	int i = 2;
	while (i*i <= k) {
		while (k % i == 0) {
			f.push_back(i);
			k /= i;
		}
		i++;
	}
	if (k > 1) f.push_back(k);

	return f;
}

int solve() {
	// cout << INF << "\n";

    int a,b,c,k;
	cin >> a >> b >> c >> k;

	int combs = 0;
	loop(x,1,a+1) {
		loop(y,1,b+1) {
			int z = k / (x*y);
			if (x*y*z != k) continue;

			combs = max(combs, (a+1 - x)*(b+1 - y)*(c+1 - z));
		}
	}

	return combs;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}
