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

	vec<int> p(n), s(n);
	p[0] = v[0];
	s[n-1] = v[n-1];

	loop(i,1,n) p[i] = v[i] + p[i-1];
	for (int i = n-2; i >= 0; i--) s[i] = v[i] + s[i+1];

	int i = 0;
	while (i < n && p[i] <= s[i]) i++;
	cout << i << " " << n - i << "\n";


	return 0;
}
