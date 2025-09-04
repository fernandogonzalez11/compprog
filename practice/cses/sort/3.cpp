#include <bits/stdc++.h>

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
	
    int n,x; cin>>n>>x;

	vec<int> p(n); loop(i,0,n) cin >> p[i];

	sort(p.begin(), p.end());
	int i = 0, j = n-1, cnt = 0;
	while (i < n && j >= i) {
		if (p[i] + p[j] > x) {
			j--;
			// a gondola just for p[j]
			cnt++;
		} else {
			j--;
			i++;
			// a gondola for both
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
