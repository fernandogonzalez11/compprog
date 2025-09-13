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

void solve() {
    int n;
	cin >> n;

	vec<int> v(n), freq(n+1,0);
	loop(i,0,n) {
		cin >> v[i];
		freq[v[i]]++;
	}

	loop(i,0,n) {
		if (freq[v[i]] < v[i] || freq[v[i]] % v[i] != 0) {
			cout << "-1\n";
			return;
		}
	}

	int id = 1;
	vec<int> firstID(n+1, -1);
	loop(i,0,n) {
		if (firstID[v[i]] != -1) continue;
		firstID[v[i]] = id;
		id += freq[v[i]] / v[i];
	}

	// printarr(firstID);

	loop(i,0,n) {
		freq[v[i]]--;
		cout << firstID[v[i]] + (freq[v[i]]/v[i]) << " ";
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
