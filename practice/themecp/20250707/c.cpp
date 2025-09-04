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
    // n is even / odd makes a difference?

	// even:
	// min: use all nums on b
	// max: dont do anything

	// odd:
	// min: dont do anything
	// max: use all nums on b

	// calc xor of all a
	
	// dont do anything:
	// output that calc ^

	// use all nums on b:
	// or all elems in b
	// do the "reset to 0 / set to 1" thing

	int n, m;
	cin >> n >> m;

	vec<int> a(n), b(m);
	int aXor = 0, bOr = 0;
	loop(i,0,n) {
		cin >> a[i];
		aXor ^= a[i];
	}
	loop(i,0,m) {
		cin >> b[i];
		bOr |= b[i];
	}

	int mm, MM;
	mm = MM = aXor;

	// odd:
	// min: dont do anything
	// max: use all nums on b
	// bOr having 1 sets aXor
	if (n & 1) {
		loop(b,0,32) {
			if ((bOr >> b) & 1) {
				MM |= (1<<b);
			}
		}
		

	// even:
	// min: use all nums on b
	// max: dont do anything
	// bOr having 1 reset aXor
	} else {
		loop(b,0,32) {
			if ((bOr >> b) & 1) {
				mm &= ~(1<<b);
			}
		}
	}

	cout << mm << " " << MM << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
