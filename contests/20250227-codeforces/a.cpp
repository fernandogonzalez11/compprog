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
	ll n; cin >> n; // 0
	ll m = n / 15; // 0
	ll clo = m * 15; // 0
	m = (m + 1) * 3; // 3
	ll dist = n - (clo + 2); // -2
	if (dist < 0) m += dist; // 1

	cout << m << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
