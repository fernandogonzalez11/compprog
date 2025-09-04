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
	ll n, x, k; cin >> n >> x >> k;
	string s; cin >> s;

	ll i = 0;
	do {
		x += (s[i] == 'R' ? 1 : -1);
		i++;
	} while (x != 0 && i < n);

	if (i == n && x != 0) cout << 0 << "\n";
	else {
		// i has second of first 0
		// i, 2i, ..., ni < k
		cout << k / n  << "\n";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
