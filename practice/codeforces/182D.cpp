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

// O(nlogn?????) idk?????

string cmp;

bool isDivisor(string s, int c) {
	for (int i = 0; i < c; i++) {
		for (int j = i; j < s.length(); j += c) {
			if (cmp[i] != s[j]) return false;
		}
	}

	return true;
}

void solve() {
    string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() > s2.length()) swap(s1, s2);

	cmp = s1;

	// find all divisors of s1
	int n = s1.length();
	int amt = 0;
	for (int c = 1; c <= n; c++) {
		if (s1.length() % c != 0 || s2.length() % c != 0) continue;

		if (isDivisor(s1, c) && isDivisor(s2, c))
			amt++;
	}

	cout << amt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
