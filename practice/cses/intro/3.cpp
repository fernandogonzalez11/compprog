#include <bits/stdc++.h>

// macros
#define int long long
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void solve() {
    
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    string s; cin >> s;
	int a = 1, c = s[0], l = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != c) {
			c = s[i];
			a = max(a, l);
			l = 1;
		} else l++;
	}

	a = max(a, l);

	cout << a << "\n";

	return 0;
}
