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

// index of first element higher or equal to x
int closestRight(vec<int> &a, int x) {
	// a[l] < x
	// a[r] >= x
	int l = -1, r = a.size();
	while (r - l > 1) {
		int mid = (r - l) / 2 + l;
		if (a[mid] < x) l = mid;
		else r = mid;
	}
	return r;
}

// index of last element less or equal to x
int closestLeft(vec<int> &a, int x) {
	// a[l] <= x
	// a[r] > x
	int l = -1, r = a.size();
	while (r - l > 1) {
		int mid = (r - l) / 2 + l;
		if (a[mid] <= x) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; cin >> n;
	vec<int> arr(n);
	loop(i, 0, n) cin >> arr[i];
	cin >> k;

	sort(arr.begin(), arr.end());
	while (k--) {
		int l, r; cin >> l >> r;
		int lRes = closestRight(arr, l);
		int rRes = closestLeft(arr, r);
		cout << rRes - lRes + 1 << " ";
	}
	cout << "\n";

	return 0;
}
