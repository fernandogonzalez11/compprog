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

bool find(vec<int> arr, int x) {
	int lo = 0, hi = arr.size() - 1;
	// lo <= hi here because if the array is of last element
	// we can still check if it equals, and then get out if it
	// wasn't (regardless if it's > or <)
	while (lo <= hi) {
		int mid = (hi - lo) / 2 + lo;
		if (arr[mid] == x) return true;
		// higher -> this and those to the right are higher -> prune
		if (arr[mid] > x) hi = mid - 1;
		// lower  -> this and those to the left are lower -> prune
		else lo = mid + 1;
	}
	// if we got through all and never found it, it isn't there
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	vec<int> arr(n);
	loop(i, 0, n) cin >> arr[i];

	while (k--) {
		int x; cin >> x;
		cout << (find(arr, x) ? "YES" : "NO") << "\n";
	}

	return 0;
}
