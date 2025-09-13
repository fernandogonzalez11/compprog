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

int smallestDiv(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return i;
	}

	return n;
}

int solve() {
    int a,b;
	cin >> a >> b;

	if (a%2==0 && b%2==1) return -1;
	else if (a%2==1 && b%2==1) return a*b + 1;
	else {
		int smolB = smallestDiv(b);

		// cout << "s:" << smolB<<"\n";

		a *= (b/smolB);
		b = smolB;

		a += b;
		if (a % 2 == 1) return -1;
		return a;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << "\n";

	return 0;
}
