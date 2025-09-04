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

int glbOr = 0;
vec<int> v;

// https://codeforces.com/contest/1973/problem/B
void solve() {
    int n;
	cin >> n;

	vec<int> v(n);
	loop(i,0,n) {
		cin >> v[i];
		glbOr |= v[i];
	}

	int lclOr = 0;
	loop(i,0,n) {
		lclOr |= v[i];
		if (lclOr == glbOr) {
			cout << i+1 << "\n";
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
