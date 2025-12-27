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

vec<int> primes(int k) {
	vec<int> p;
	vec<bool> isp(k+2, true);

	for (int i = 2; i<=k; i++) {
		if (!isp[i]) continue;
		p.push_back(i);
		for (int j = 2*i; j <= k; j += i) isp[j] = false;
	}

	return p;
}

map<int,int> factor(vec<int> &primes, int x) {
	map<int,int> m;
	for (auto p : primes) {
		if (p > x) break;
		if (x%p==0) {
			while (x%p==0) {
				m[p]++;
				x/=p;
			}
		}
	}

	if (x>1) m[x]++;
	return m;
}

void solve() {
	int n,k;
	cin>>n>>k;
	
	vec<int> a(n), b;
	loop(i,0,n) cin >> a[i];
	sort(a.begin(),a.end());
	map<int,int> idxs;
	loop(i,0,n) idxs[a[i]] = i;
	vec<bool> cool(n);

	vec<int> ps = primes(k);
	printarr(ps);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
