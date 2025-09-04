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
	
    int n,m,k; cin>>n>>m>>k;

	vec<int> a(n); loop(i,0,n) cin >> a[i];
	vec<int> b(m); loop(i,0,m) cin >> b[i];

	sort(a.begin(),a.end(), greater<>());
	sort(b.begin(),b.end(), greater<>());

	int i = 0, j = 0, cnt = 0;
	while (i < n && j < m) {
		// in bounding box
		if (b[j] >= a[i] - k && b[j] <= a[i] + k) {
			cnt++;
			i++;
			j++;
		} else {
			if (b[j] > a[i] + k) j++;
			else i++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
