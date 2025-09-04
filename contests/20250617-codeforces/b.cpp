#include <bits/stdc++.h>
#include <unordered_set>

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

int solve() {
    int n; cin >> n;
	string s; cin >> s;

	unordered_multiset<char> cc;
	for (char c : s) cc.insert(c);

	for (char a = 'a'; a <= 'z'; a++) {
		if (cc.count(a) >= 3) return true;
		if (cc.count(a) == 2 && !(s[0] == a && s[n-1] == a)) return true;
	}

	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout << (solve() ? "Yes" : "No") << "\n";

	return 0;
}
