#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

void swap(vec<int> &a, int i, int j) {
	if (a[i] < a[j]) {
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
	}
}

bool check(int fi, int fp, vec<int> &v) {
	if (v[0] < fi + fp) return false;
	if (v[1] < fi || v[2] < fi) return false;
	return true;
}

void solve() {
    int n,m; cin >> n >> m;

	int fi = 2, fp = 1;
	loop(i, 2, n) {
		int tmp = fi;
		fi += fp;
		fp = tmp;
	}

	// cout << fi << " " << fp << "\n";

	loop(i,0,m) {
		vec<int> v(3);
		loop(i,0,3) cin >> v[i];
		
		swap(v, 0,1);
		swap(v,0,2);

		// cout << v[0] << " " << v[1] << " " << v[2] << "\n";

		cout << check(fi, fp, v);
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
