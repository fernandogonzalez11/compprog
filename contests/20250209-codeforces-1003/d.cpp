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

// which one should go first? asks c++
bool prefixcomp(const vec<ll> &a, const vec<ll> &b) {
	int m = a.size();
	if (a[m - 1] == b[m - 1]) {
		loop(i, 0, m - 1) {
			if (a[i] != b[i]) return a[i] > b[i];
		}
	}
	return a[m - 1] > b[m - 1];
}

void process() {
	int n, m; cin >> n >> m;
	vec<vec<ll>> nums;

	loop(i, 0, n) {
		vec<ll> nns(m);
		loop(j, 0, m)
			cin >> nns[j];
		
		nums.push_back(nns);
	}

	// make prefixes
	loop(i, 0, n) {
		for (int j = 1; j < m; j++)
			nums[i][j] += nums[i][j - 1];
	}

	/* cout << "--- arr\n";
	loop(i, 0, n) {
		loop(j, 0, m) cout << nums[i][j] << " ";
		cout << "\n";
	}
	cout << "---\n"; */

	// sort in O(n²logn) because of special comp
	sort(nums.begin(), nums.end(), prefixcomp);

	/* cout << "--- sorted\n";
	loop(i, 0, n) {
		loop(j, 0, m) cout << nums[i][j] << " ";
		cout << "\n";
	}
	cout << "---\n"; */

	// get total sum through prefixes
	ll sum = 0, lastpref = 0;
	loop(i, 0, n) {
		// last pref
		ll localsum = 0;
		loop (j, 0, m) localsum += nums[i][j];
		sum += lastpref * m + localsum;
		lastpref += nums[i][m - 1];
	}
	cout << sum << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) process();

	return 0;
}
