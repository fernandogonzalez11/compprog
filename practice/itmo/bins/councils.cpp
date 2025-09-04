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

int k, n; 
vec<int> v;
int S = 0;

// ¿puedo hacer x grupos de k personas?
bool ok(int x) {
	int s = 0;
	// si un grupo tiene más que x personas, por el principio del palomar
	// unas de ellas van a quedar fuera
	loop(i,0,n) s += min(x, v[i]);
	// ahora hacemos como que agrupamos en línea nuestras personas elegidas
	// lo cual nos da una suma de personas

	return s >= k*x;
}

void solve() {
    cin >> k >> n;
	v.resize(n);
	loop(i,0,n) cin >> v[i];

	sort(v.begin(), v.end());
	


	int l = 0, r = 1;
	while (ok(r)) r *= 2;

	// loop(i,l,r+1) cout << ok(i);
	// cout << "\n";

	while (r-l>1) {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	cout << l << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
