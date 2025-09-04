#include <bits/stdc++.h>
#include <functional>

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
	vec<int> v(n);

	loop(i,0,n) cin >> v[i];
	sort(v.begin(), v.end(), greater<>());

	int em = 0;
	for (int i = 0; i < n/2*2; i+=2) em += v[i];
	if (n % 2 != 0) em += v[n-1];

	cout << em << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
