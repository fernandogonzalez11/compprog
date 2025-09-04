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

using namespace std;

// does alice win
bool solve() {
    int n, k; cin >> n >> k;
	string s; cin >> s;

	int ones = 0;
	loop(i,0,s.size()) ones += (s[i] == '1');

	if (ones <= k) return true;

	loop(i,0,ones) s[i] = '1';
	loop(i,ones,s.size()) s[i] = '0';

	// overlap
	if (s[n-k] == '1') {
		ones -= ones - (n-k+1);
	}

	return ones <= k;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "Alice\n" : "Bob\n");

	return 0;
}
