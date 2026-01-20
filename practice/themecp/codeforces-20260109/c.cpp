#include <algorithm>
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

void solve() {
	int n;
	cin>>n;

	vec<int> v(n);
	loop(i,0,n) cin>>v[i];

	map<int,int> freq;
	loop(i,0,n) freq[v[i]]++;

	vec<int> freq_v;

	for (auto [k,v] : freq) {
		freq_v.push_back(v);
	}

	vec<int> freq_p(freq_v.size());

	partial_sum(all(freq_v), freq_p.begin());

	// printarr(freq_v);
	// printarr(freq_p);

	int amt = 0;

	loop(i,0,freq_v.size()) {
		int f = freq_v[i];
		int comb3 = (f<3) ? 0 : (f*(f-1)*(f-2)/6);
		int combO = (f<2 || i==0) ? 0 : (f*(f-1)/2 * freq_p[i-1]);
		amt += comb3 + combO;
	}

	cout << amt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
