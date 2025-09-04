#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define MOD 1000000007
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

ll proc() {
	ll n, k; cin >> n >> k;

	ll sum = 0;
	for (ll b = 0; b < k; b++) {
		int n2 = n;
		ll lsum = 0;
		while (n2 > 0) {
			lsum = (lsum * 10) % MOD;
			lsum = (lsum + (n2 % b)) % MOD;
			n2 /= b;
		}
		sum += lsum;
		sum %= MOD;
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) cout << proc() << "\n";

	return 0;
}
