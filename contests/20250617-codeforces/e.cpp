#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 63)
#define int long long

using namespace std;

int res(string l, string r) {
	int amt = 0;
	int i = 0;
	while (l[i] == r[i]) {
		amt += 2;
		i++;
	}

	// it cant be the same number because it wouldve fallen in the cond above
	// if theres a "hole" between the two digits we're done cuz we can always
	// pick a number in between that doesn't match any of the other two
	if (r[i] - l[i] >= 2) return amt;
	// if theres no hole we have two options: choose the first number or the second one
	else {
		return amt + min(1 + , 1 + )
	}
}

void solve() {
    string l, r;
	cin >> l >> r;

	cout << res(l, r);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
