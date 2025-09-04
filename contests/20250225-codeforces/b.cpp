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


ll proc() {
	ll ones = 0;
	ll n; cin >> n;
	string s; cin >> s;
	loop(i, 0, n) ones += (s[i] == '-');

	ll zeros = n - ones;

	ll ones1 = ones / 2;
	ll ones2 = ones - ones1;

	// there has to be at least 1 of each category
	// otherwise this will be 0
	return ones1 * zeros * ones2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) cout << proc() << "\n";

	return 0;
}
