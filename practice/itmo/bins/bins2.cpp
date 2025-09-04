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

int closestRight(vec<int>& arr, int x) {
	// virtual elements: -INF at left, INF at right
	// invariants:
	// 	a[l] <= x
	//  a[r] > x
	int l = -1, r = arr.size();
	// end up with a pair of elements
	while (r - l > 1) {
		int mid = (r - l) / 2 + l;
		// greater than x -> elems to the right are greater
		// mid instead of mid - 1 to keep invariant
		if (arr[mid] > x) r = mid;
		// less or equal than x -> elems to the left as well
		else l = mid;
	}

	// l: <=, r: >
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	vec<int> arr(n);
	loop(i, 0, n) cin >> arr[i];

	while (k--) {
		int x; cin >> x;
		int res = closestRight(arr, x);
		// -1 converts to 0
		// by casualty, we need to output as 1-indexed vals :)
		cout << res + 1 << "\n";
	}

	return 0;
}
