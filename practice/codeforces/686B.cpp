#include <bits/stdc++.h>
#include <functional>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void solve() {
    
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int n; cin >> n;
	vec<int> v(n); loop(i,0,n) cin >> v[i];

	
	vec<int> vC = v;

	sort(vC.begin(), vC.end(), greater<>());

	int cur = n - 1;
	loop(i,0,n-1) {
		// search elem 
		int j = 0;
		for (; j < n; j++) {
			if (vC[i] == v[j]) break;
		}

		if (j != cur) {
			// upto cur-1 with cur
			while (j < cur) {
				cout << j+1 << " " << j+2 << "\n";
				// swap
				v[j] ^= v[j+1];
				v[j+1] ^= v[j];
				v[j] ^= v[j+1];

				j++;
			}
			// loop(k,0,n) cout << v[k] << " ";
			// cout << "\n";
		}
		cur--;
	}
	

	return 0;
}
