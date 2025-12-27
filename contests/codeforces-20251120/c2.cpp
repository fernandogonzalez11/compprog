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

int findFirstDiff(int a, int b) {
	int i = 32;
	for (; i >= 0; i--) {
		if (((a&(1<<i))==0) == ((b&(1<<i))==0)) break;
	}

	return i;
}

void solve() {
    int n;
	cin >> n;
	vec<int> a(n),b(n);
	loop(i,0,n) cin >> a[i];
	loop(i,0,n) cin >> b[i];

	int na=a[0], nb=b[0];
	loop(i,1,n) {
		na ^= a[i];
		nb ^= b[i];
	}
	
	int diffBit = findFirstDiff(na, nb);

	loop(i,0,n) {
		int na2 = na ^ a[i] ^ b[i];
		int nb2 = nb ^ b[i] ^ a[i];

		if (i%2==0) { // aji
			if (na2 > na) {
				na = na2;
				nb = nb2;
			}
		} else { // mai
			if (nb2 > nb) {
				na = na2;
				nb = nb2;
			}
		}
	}

	if (na==nb) cout << "Tie\n";
	else if (na>nb) cout << "Ajisai\n";
	else cout << "Mai\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
