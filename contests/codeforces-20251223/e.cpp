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
    int n,x,y;
	cin>>n>>x>>y;

	string s;
	cin>>s;

	vec<int> p(n);
	loop(i,0,n) cin >> p[i];

	vec<int> a(n,0),b(n,0);
	int twosdiffa(0), twosdiffb(0);
	loop(i,0,n) {
		if (s[i]=='0') {
			a[i] = (p[i]%2) ? 1 : 2;
			x -= a[i];
			twosdiffa += a[i]>1;
		} else  {
			b[i] = (p[i]%2) ? 1 : 2;
			y -= b[i];
			twosdiffb += b[i]>1;
		}
	}

	// cout << x << " " << y << "\n";
	// printarr(a);
	// printarr(b);

	if (x<0||y<0||(x>y && twosdiffa<(x-y))||(y>x && twosdiffb<(y-x))) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
