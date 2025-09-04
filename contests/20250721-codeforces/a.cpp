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
    string s;
	cin >> s;
	vec<int> freq(26,0);
	loop(i,0,s.size()) {
		freq[s[i] - 'A']++;
	}

	// printarr(freq);

	int idx = 0;
	int i = 0;
	for (i = 0; i < freq['T' - 'A']; i++) s[i] = 'T';
	idx += freq['T' - 'A'];
	freq['T' - 'A'] = 0;

	loop(i,0,26) {
		loop(j,0,freq[i]) {
			s[idx++] = (char) 'A' + i;
		}
	}

	cout << s << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
