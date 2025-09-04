#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void proc() {
	ll n, x; cin >> n >> x;

	ll i = 0;
	while (i < x) {
		ll mask = x & (1 << i);
		if (!mask) break;
		i++;
	}

	// 0 to u
	ll numsCnt = (1 << (i + 1));
	numsCnt = min(n - 1, numsCnt);
	ll comp = n - numsCnt;

	ll sum = 0;
	for (ll i = 0; i < numsCnt - 1; i++) {
		cout << i << " ";
		sum |= i;
	}
	if ((sum | (numsCnt - 1)) == x) cout << (numsCnt - 1) << " ";
	else cout << x << " ";
	for (ll i = 0; i < comp; i++) cout << x << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
