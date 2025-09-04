#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for (auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

bool check(vec<int> &a) {
	for (int i = 0; i < a.size() - 4; i++) {
		if (a[i] < a[i+1] && a[i+1] < a[i+2] && a[i+2] < a[i+3] && a[i+3] < a[i+4]) return false;
		if (a[i] > a[i+1] && a[i+1] > a[i+2] && a[i+2] > a[i+3] && a[i+3] > a[i+4]) return false;
	}
	return true;
}

void solve() {
    int n;
	cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	int l, r, i;

	l = 0;
	r = n-1;
	i = 0;
	vec<int> result(n, -1);

	result[i++] = v[l++];
	result[i++] = v[l++];
	cout << "LL";

	while (i < n) {
		// inc
		bool inc = result[i-2] < result[i-1];
		if (inc) {
			bool worksl = result[i-1] > v[l];
			bool worksr = result[i-1] > v[r];

			char smaller = v[l] < v[r] ? 'L' : 'R';
			char bigger = v[l] > v[r] ? 'L' : 'R';

			if (worksl && worksr) {
				if (smaller == 'L') {
					result[i++] = v[l++];
					cout << "L";
				} else {
					result[i++] = v[r--];
					cout << "R";
				}
			} else if (worksl && !worksr) {
				result[i++] = v[l++];
				cout << "L";
			} else if (!worksl && worksr) {
				result[i++] = v[r--];
				cout << "R";
			} else {
				if (bigger == 'L') {
					result[i++] = v[l++];
					cout << "L";
				} else {
					result[i++] = v[r--];
					cout << "R";
				}
			}
		} else {
			bool worksl = result[i-1] < v[l];
			bool worksr = result[i-1] < v[r];

			char smaller = v[l] < v[r] ? 'L' : 'R';
			char bigger = v[l] > v[r] ? 'L' : 'R';

			if (worksl && worksr) {
				if (bigger == 'L') {
					result[i++] = v[l++];
					cout << "L";
				} else {
					result[i++] = v[r--];
					cout << "R";
				}
			} else if (worksl && !worksr) {
				result[i++] = v[l++];
				cout << "L";
			} else if (!worksl && worksr) {
				result[i++] = v[r--];
				cout << "R";
			} else {
				if (smaller == 'L') {
					result[i++] = v[l++];
					cout << "L";
				} else {
					result[i++] = v[r--];
					cout << "R";
				}
			}		
		}
	}

	cout << "\n";
	// printarr(result);
	// cout << check(result) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
