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
	string a,b;
	cin>>a>>b;

	if (a[0]==b[0]) {
		cout << "YES\n" << a[0] << "*\n"; 
		return;
	}
	else if (*a.rbegin()==*b.rbegin()) {
		cout << "YES\n" << "*" << *a.rbegin() << "\n";
		return;
	}
	else {
		loop(i,0,a.size()-1) loop(j,0,b.size()-1) {
			if (a[i]==b[j] && a[i+1]==b[j+1]) {
				cout << "YES\n" << "*" << a[i] << a[i+1] << "*\n";
				return;
			}
		}
	}

	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
