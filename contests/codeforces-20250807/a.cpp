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

bool works(deque<int> &a, vec<int> &b) {
	loop(i,0,a.size()) {
		if (a[i] > b[i]) return false;
	}

	return true;
}

void solve() {
    int n;
	cin >> n;

	deque<int> a(n);
	vec<int> b(n);
	loop(i,0,n) cin >> a[i];
	loop(i,0,n) cin >> b[i];

	int i = 0;
	while (!works(a,b)) {
		a.pop_back();
		a.push_front(1);
		i++;
	}

	cout << i << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
