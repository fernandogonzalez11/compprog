#include <bits/stdc++.h>
#include <numeric>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) /*cout << #a << ": ";*/ \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
    int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	loop(i,1,n-1)
		if (v[i]==-1) v[i]=0;

	if (v[0]==-1 && v[n-1]==-1) v[0]=v[n-1]=0;
	else if (v[0]==-1) v[0]=v[n-1];
	else if (v[n-1]==-1) v[n-1]=v[0];

	cout << abs(v[n-1]-v[0]) << "\n";
	printarr(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
