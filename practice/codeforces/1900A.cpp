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

int solve() {
    int n;
	cin >> n;

	string s;
	cin >> s;

	int i = 0;
	int M = -1, S = 0;
	while (i < n) {
		if (s[i] == '.') {
			int start = i;
			while (i < n && s[i] == '.') i++;
			int end = i;
			M = max(M, end-start);
			S += end-start;
		} else i++;
	}

	if (M >= 3) return 2;
	else return S;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) cout<<solve()<<"\n";

	return 0;
}
