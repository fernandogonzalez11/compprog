#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)

using namespace std;

void solve() {
    int n; cin >> n;
	string s; cin >> s;
	int i;
	int g = 0, b = 0;
	bool fck = false;
	for (i = 0; i < n; i++) {
		if (s[i] == 'G') g++;
		else b++;

		if (b > 2 * g) {
			fck = true;
			break;
		}
	}

	cout << (fck ? (i + 1) : i) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int t; cin >> t;
    while (t--) solve();

	return 0;
}
