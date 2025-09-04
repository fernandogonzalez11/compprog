#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define MOD 998244353

using namespace std;

void proc() {
	ll n; cin >> n;
	vec<ll> dists(n + 1, 0);
	vec<ll> distCounts(n + 1, 0);

	ll maxDistI = 0;
	loop(i, 1, n + 1) {
		ll p; cin >> p;
		p--;
		ll d = dists[p] + 1;
		dists[i] = d;
		distCounts[d]++;
		maxDistI = max(maxDistI, d);
	}

	ll valid = 1;
	/*cout << "----\n";
	loop(i, 0, n) cout << dists[i] << " ";
	cout << "\n";
	loop(i, 0, n) cout << distCounts[i] << " ";
	cout << "\n";
	cout << maxDistI << "\n";*/
	loop(i, 0, maxDistI) {
		for (int j = 1; j <= distCounts[i]; j++)
			valid = (valid * j % MOD) % MOD;
	}

	cout << valid << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
