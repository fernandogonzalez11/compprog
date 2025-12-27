#include <bits/stdc++.h>
#include <iomanip>

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

double p,a,b,c,d;

double calc(double k) {
	return p * (sin(a*k+b)+cos(c*k+d)+2);
}

void solve() {
    cin>>p>>a>>b>>c>>d;

	int n;
	cin >> n;
	vec<double> v(n);
	loop(i,1,n+1) {
		v[i-1] = calc(i);
	}

	// printarr(v);

	double M = v[0], m = v[0], dec = 0;
	loop(i,1,n) {
		if (v[i] > M) {
			M = v[i];
			m = v[i];
		}
		m = min(v[i], m);
		dec = max(dec, M-m);
	}

	cout<<fixed<<dec<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
