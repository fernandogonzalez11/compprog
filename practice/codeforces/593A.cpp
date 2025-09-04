#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1 << 30) + (1 << 25)
#define int long long

#define LETTERS 26

using namespace std;

void solve() {
    int n; cin >> n;

	vec<vec<int>> freq(n, vec<int>(LETTERS, 0));
	vec<int> exists(n, 0);

	// m: letters on word
	// O(n * m)
	loop(i,0,n) {
		string s; cin >> s;
		for (char c : s) {
			int idx = c - 'a';
			freq[i][idx]++;
			exists[i] |= (1<<idx);
		}
	}

	// loop(i,0,n) {
	// 	loop(j, 0, LETTERS) cout << freq[i][j] << " ";
	// 	cout << "\n";
	// }

	int maxLetters = 0;
	// O(429 * n)
	loop(i,0,LETTERS-1) {
		loop(j,i+1, LETTERS) {
			int mask = (1<<i) | (1<<j);
			int s = 0;
			loop(k,0,n) {
				if ((exists[k] | mask) != mask) continue;
				s += freq[k][i] + freq[k][j];
			}

			maxLetters = max(maxLetters, s);
		}
	}

	cout << maxLetters << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}
