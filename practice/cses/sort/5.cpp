#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL < 63)
#define int long long

using namespace std;

void solve() {
    int n;
	cin >> n;

	vec<int> arr(n), dep(n);
	loop(i,0,n) cin >> arr[i] >> dep[i];

	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	int i = 0, j = 0;
	int final = 0;
	int cnt = 0;
	while (i < n || j < n) {
		// can't get better than this
		if (i >= n) break;
		if (j >= n || arr[i] < dep[j]) {
			final = max(final, ++cnt);
			// cout << "new " << i << " " << j << " " << final << "\n"; 
			i++;
		} else {
			cnt--;
			j++;
		}
	}

	cout << final << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
