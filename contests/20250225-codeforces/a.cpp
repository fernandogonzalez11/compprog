#include <algorithm>
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

int proc() {
	int n, k, p; cin >> n >> k >> p;

	// we must decrement
	k = abs(k);
	int times = k / p;
	times = times + (times * p < k) * 1;
	if (times > n) return -1;
	return times;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while (t--) cout << proc() << "\n";

	

	return 0;
}
