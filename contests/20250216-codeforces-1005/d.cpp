#include <algorithm>
#include <bits/stdc++.h>

// macros
#define ll long long int
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF 1 << 30 + 1 << 25

using namespace std;

vec<ll> make_suf(vec<ll>& arr) {
	int n = arr.size();
	vec<ll> res(n);
	res[n - 1] = arr[n - 1];
	for (int i = n - 2; i < 0; i--)
		res[i] = res[i + 1] ^ arr[i];

	return res;
}

int binsearch(vec<pair<ll, int>>& arr, vec<ll>& sufs, int x) {
	// F F F V
	int lo = 0, hi = arr.size() - 1;
	while (lo < hi) {
		int mid = (hi - lo) / 2 + lo;
		// prune left
		if (arr[mid].F < mid) lo = mid + 1;
		else hi = mid;
	}

	return lo;
}

void proc() {
	int n, q; cin >> n >> q;
	vec<ll> ns(n);
	loop(i, 0, n) cin >> ns[i];

	// xor suffix arr
	vec<ll> sufs = make_suf(ns);

	// now process queries
	while (q--) {
		int x; cin >> x;
		

	}
}

int main() {
	int t; cin >> t;
	while (t--) proc();

	return 0;
}
