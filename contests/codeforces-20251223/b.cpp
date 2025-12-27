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
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

void solve() {
    int n;
	cin>>n;
	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	vec<int> diff(n);
	diff[0]=0;
	loop(i,1,n) {
		diff[i] = abs(v[i]-v[i-1]);
	}

	int s = accumulate(diff.begin(),diff.end(),0LL);
	int m = min(s-diff[1],s-diff[n-1]);
	loop(i,1,n-1) {
		int c = s-diff[i]-diff[i+1]+abs(v[i+1]-v[i-1]);
		m = min(m,c);
	}

	cout << m << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
