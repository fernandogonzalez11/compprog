#include <bits/stdc++.h>
#include <numeric>

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
    vec<int> counts(26,0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	loop(i,0,n) {
		char c = s[i];
		counts[c - 'a']++;
	}

	sort(counts.begin(), counts.end(), greater());
	// printarr(counts);

	// int i = 0, j = 1;
	// while (j < n) {
	// 	int rm = min(counts[i], counts[j]);
	// 	counts[i] -= rm;
	// 	counts[j] -= rm;

	// 	if (counts[i] == 0) {
	// 		i++;
	// 		j = max(i+1, j);
	// 	} else j++;
	// }

	int h = n-1;
	while (counts[h] == 0) h--;

	int sI = 0;
	loop(i,0,s.length()) {
		s[sI++] = (i%(h+1)) + 'a';
	}

	cout << s << "\n";

	stack<char> ss;
	loop(i,0,n) {
		if (ss.empty()) ss.push(s[i]);
		else if (ss.top() != s[i]) ss.pop();
		else ss.push(s[i]);
	}

	cout << ss.size() << "\n";


	// cout << accumulate(counts.begin(), counts.end(), 0) << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
