#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(n) n.begin(), n.end()
#define F first
#define S second
#define printarr(a) cout << #a << ": "; \
	for (auto x : a) cout << x << " "; \
	cout << "\n";

using namespace std;
using ll = long long;
using pii = pair<int,int>;

// constants
const int INF = 1LL << 62;
const int MOD = 1e9 + 7;

int mex(vec<int> &v) {
	set<int> s(all(v));
	int res = 0;
	while (s.count(res)) res++;
	return res;
}

void solve() {
	int n;
	cin>>n;
	vec<int> v(n);

	int za = 0;
	loop(i,0,n) {
		cin>>v[i];
		za += v[i]==0;
	}

	sort(all(v));
	bool works = true;

	for (auto a = v.begin(); a != v.end(); a++) {
		vec<int> v1(v.begin(), a+1);
		vec<int> v2(a+1, v.end());
		// printarr(v1);
		// printarr(v2);

		int m1 = mex(v1), m2 = mex(v2);
		works &= (m1 != m2);
	}

	// bool can = za > 0 && mex(v) > 1;
	cout << (works ? "YES\n" : "NO\n");

	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
