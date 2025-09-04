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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	int g = gcd(a, b);
	return a / g * b;
}

void solve() {
    int a,b;
	cin >> a >> b;

	int l = lcm(a,b);

	if (b < l) {}
	else {
		int firstP = -1;
		for (int i = 2; i*i <= l; i++) {
			if (l % i == 0) {
				firstP = i;
				break;
			}
		}

		if (firstP == -1) firstP = l;

		l *= firstP;
	}

	cout << l << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
