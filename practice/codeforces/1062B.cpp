#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

map<int, int> factors(int n) {
	map<int, int> f;
	int i = 2;
	while (n > 1) {
		while (n % i == 0) {
			f[i]++;
			n /= i;
		}
		i++;
	}

	return f;
}

bool powerOf2(int n) {
	return (n & (n - 1)) == 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n; cin >> n;
	map<int, int> f = factors(n);

	int maxLog = 0;
	bool skipFirstStep = 0;

	int _cur = 0, _passed = 0;
	for (auto x : f) {
		if (!powerOf2(x.second)) break;
		if (!_passed) _cur = x.second;
		if (x.second != _cur) break;
		_passed++;
	}
	skipFirstStep = _passed == f.size();

	// best number will be only 1 instance of each prime factor (min we can have)
	int tot = 1;

	for (auto x : f) {
		tot *= x.first;

		// find closest power to 2 for the max, in log form
		// if it's already a power of 2, we only need log(n)
		// otherwise, it should be log(n) + 1
		int curNonPow2 = !powerOf2(x.second);
		// cout << ((int) log2(x.second)) + curNonPow2 << "\n";
		maxLog = max(maxLog, ((int) log2(x.second)) + curNonPow2);
	}

	cout << tot << " " << maxLog + (int) !skipFirstStep << "\n";

	return 0;
}
