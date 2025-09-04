#include <bits/stdc++.h>
#include <unordered_set>

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
    int n; cin >> n;
	unordered_set<int> s;
	vec<int> a(n); loop(i,0,n) {
		cin >> a[i];
		s.insert(a[i]);
	} 

	sort(a.begin(), a.end());

	int cnt = 0;
	for (int i = n-1; cnt < n/2; i--) {
		cout << a[i] << " " << a[0] << "\n";
		cnt++;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
