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

// interesting recursive outlook but its not what we should be doing

// set<int> route = set<int>();

// bool can(int n, int k) {
// 	if (n == 0) return true;
// 	if (k < 0 || k*(k+1)/2 < n) return false;

//     if (can(n-k, k-1)) {
// 		route.insert(k);
// 		return true;
// 	} else {
// 		return can(n, k-1);
// 	}
// }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n; cin >> n;
	int t = n*(n+1)/2;
	if (t % 2 != 0) {
		cout << "NO\n";
		return 0;
	}

	t /= 2;
	// int i = 1;
	// // linear search, can be done better through bin search!
	// while (i*(i+1)/2 < t) i++;

	int acc = 0;
	int i = n;
	for (; i > 0; i--) {
		if (acc + i >= t) break;
		acc += i;
	}
	i++;

	cout << "YES\n";
	// set 1
	int comp = t - acc;
	cout << n - i + 1 + 1 << "\n";
	loop(j, i, n+1) cout << j << " ";
	cout << comp << "\n";

	// set 2
	cout << i - 1 - 1 << "\n";
	loop(j, 1, i)
		if (j != comp) cout << j << " ";
	cout << "\n";

	// i--;

	// cout << "YES\n";

	// // set 1
	// cout << i << "\n";
	// loop(j, 1, i+1) cout << j << " ";

	// int comp = t - i*(i+1)/2;
	// cout << comp << "\n";

	// // set 2
	// cout << n - (i + 1) << "\n";
	// loop(j, i+1, n+1)
	// 	if (j != comp) cout << j << " ";
	// cout << "\n";

	return 0;
}
