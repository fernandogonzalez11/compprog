#include <algorithm>
#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

vec<int> v;
int mmax;

// format VVVVVFFFF
bool ok1(int s, int i) {
	return s > v[i];
}

// format FFFFVVVVVV
bool ok2(int s, int i) {
	return s + v[i] > mmax;
}

void solve() {
    int n;
	cin >> n;
	v.resize(n);
	loop(i,0,n) cin >> v[i];

	sort(v.begin(), v.end());

	mmax = v[n-1];

	int gcnt = 0;
	loop(i,0,n-2) {
		loop(j,i+1,n-1) {
			int s = v[i] + v[j];
			// loop(k,j+1,n) {
			// 	if (k == n && !(v[k] >= s)) cnt++;
			// 	else if (!(m >= s + v[k] || v[k] >= s)) cnt++;
			// }

			int cnt = 0;

			if (j != n-2) {
				// s + v[k] > mmax
				// v[k] > mmax - s (left edge)
				// find first k s.t. v[k] > mmax - s (upper_bound)
				// = left

				// s > v[k]
				// v[k] < s (right edge)
				// find last k s.t. v[k] < s
				// find first k s.t. v[k] >= s (lower_bound), then decrement
				// = right

				// range: r - l + 1 = (r + 1) - l = lower_bound - upper_bound

				auto left = upper_bound(v.begin() + j + 1, v.end() - 1, mmax - s);
				auto right = lower_bound(v.begin() + j + 1, v.end() - 1, s);

				// if left is .end(), there's no range
				// if right is .begin(), there's no range
				if (left < v.end() && right > v.begin() + j && left <= right - 1) {
					cnt += right - left;
				}
			}

			if (ok1(s, n-1)) cnt++;

			// cout << i << " " << j << " " << cnt << "\n";
			gcnt += cnt;
		}
	}

	cout << gcnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
