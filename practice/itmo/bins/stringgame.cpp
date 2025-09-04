#include <bits/stdc++.h>
#include <unordered_set>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

using namespace std;

string t, p;
int n, m;
vec<int> v;

bool ok(int x) {
	unordered_set<int> perm;
	loop(j,0,x+1) perm.insert(v[j]);

	int i = 0, j = 0;
	while (i < n && j < m) {
		if (perm.count(i)) i++;
		else {
			if (t[i] == p[j]) {
				i++;
				j++;
			} else {
				i++;
			}
		}
	}

	return j == m;
}

void solve() {
    cin >> t >> p;
	n = t.size();
	m = p.size();
	
	v.resize(n);
	loop(i,0,n) {
		cin >> v[i];
		v[i]--;
	}

	// loop(i,0,n) cout << ok(i);
	// cout << "\n";

	if (!ok(0)) {
		cout << 0 << "\n";
		return;
	}

	int l = 0, r = n;
	while (r-l > 1) {
		int m = (r-l)/2+l;
		if (ok(m)) l = m;
		else r = m;
	}

	cout << l+1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
