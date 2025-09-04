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
	
    int n; cin >> n;
	vec<int> v(n);
	loop(i,0,n) cin >> v[i];

	sort(v.begin(),v.end());
	int rep = 0;
	loop(i,1,n) {
		if (v[i] == v[i-1]) rep++;
	}

	cout << n - rep << "\n";

	return 0;
}
