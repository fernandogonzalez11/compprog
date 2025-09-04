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
	ll n; cin >> n;

	ll sum = 0;
	
	loop(i, 0, n) {
		ll x; cin >> x;
		sum += x;
		//cin >> a[i];
	}
	
	cout << sum - (n - 1) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) proc();

	return 0;
}