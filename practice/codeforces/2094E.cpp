// https://codeforces.com/contest/2094/problem/E

#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define BITS 30
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
	vec<int> ns(n);
	loop(i, 0, n) cin >> ns[i];

	// frequency of ones by bit
	// O(30n), as 30 is the amount of bits
	vec<int> ones(BITS);
	for (int num : ns) {
		for (int b = 0; b < BITS; b++) {
			ones[b] += (((1 << b) & num) > 0);
		}
	}

	// loop(i, 0, BITS) cout << ones[i] << " ";
	// cout << "\n";

	// we have to maximize the number of 1s per bit when we make the sum, so
	// for each bit
	// if ones[i] is more than half the nums, set to 0
	// since 1 xor 0 = 1, so result will have more 1s
	// if there are more 0s, set to 1
	// since 0 xor 1 = 1
	int h = n / 2; // if n is odd, we'll need to check whether ones[i] > h

	// this will give me the best number of all the integers, but we need it to be in the array
	// int res = 0;
	// loop(i, 0, BITS) {
	// 	res |= (ones[i] > h) << i;
	// }

	ll res = 0;
	for (int num : ns) {
		ll sum = 0;
		loop(b, 0, BITS) {
			// if the bit is 1, there are n - ones[i] 0s that
			// will give you 1 when you do the xor for that bit
			if ((num & (1 << b)) > 0) {
				sum += (n - ones[b]) * (1 << b);
			// if the bit is 0, there are ones[i] 1s
			} else {
				sum += ones[b] * (1 << b);
			}
		}

		res = max(res, sum);
	}

	cout << res << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
